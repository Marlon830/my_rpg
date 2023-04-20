/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_pos_in_tiles.c
*/

#include "attack_mode.h"

sfVector2f get_pos_in_tiles(combat_map_t *map, tile_t *tile)
{
    int tile_y = tile->ind % map->height;
    int tile_x = (tile->ind - tile_y) / map->height;
    return (sfVector2f){tile_x, tile_y};
}

void dichotomie(float a, float b, float x)
{
    float mid = (a - b) / 2;
    if (mid < x - .01 && x + .01 < mid) {
        if (mid < x - .01)
            dichotomie(mid, b, x);
        else
            dichotomie(a, mid, x);
    }
}
