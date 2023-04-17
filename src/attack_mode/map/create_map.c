/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_map.c
*/

#include "attack_mode.h"

void create_map_two(combat_map_t *res)
{
    res->hovered_tile = res->tiles[0];
    res->far_tile = create_tile((sfVector2f)
    {-100, -100}, sfWhite, (sfVector2f){1, 1}, 0);
    res->far_tile->ind = -1;
}

combat_map_t *create_map(int width, int height, sfVector2f decalage,
sfVector2f size)
{
    combat_map_t *res = malloc(sizeof(combat_map_t));
    sfColor color = sfWhite;
    int j = 0;
    tile_t **tile_list = malloc(sizeof(tile_t *) * width * height);
    for (float x = 0; x < width; x++) {
        for (float y = height - 1; y >= 0; y--) {
            sfVector2f pos = (sfVector2f){(x * (size.x + 5) + y
            * (size.x + 5)) / 2 + decalage.x, (x * (size.x + 5) - y *
            (size.x + 5)) / (2 * (size.x / size.y)) + decalage.y};
            tile_list[j] = create_tile(pos, color, size, 40);
            tile_list[j]->ind = j;
            j++;
        }
    }
    res->pos = decalage;
    res->width = width;
    res->height = height;
    res->tiles = tile_list;
    create_map_two(res);
    return res;
}
