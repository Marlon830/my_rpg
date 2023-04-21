/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_map.c
*/

#include "attack_mode.h"

void update_map(sfRenderWindow *window, combat_map_t *map, sfEvent event)
{
    map->mousePos = (sfVector2f){event.mouseMove.x, event.mouseMove.y};
    map->mousePos = convert_mouse_window(window, event.mouseMove.x,
    event.mouseMove.y);
    int b = 0;
    for (int i = 0; i < map->height * map->width; i++) {
        if (is_point_in_diamond(map->mousePos, map->tiles[i])) {
                map->hovered_tile = map->tiles[i];
                b = 1;
            }
    }
    if (!b)
        map->hovered_tile = map->far_tile;
}
