/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_map.c
*/

#include "attack_mode.h"

void draw_map(sfRenderWindow *window, combat_map_t *map)
{
    for (int i = 0; i < map->height * map->width; i++) {
        draw_tile(window, map->tiles[i]);
    }
}
