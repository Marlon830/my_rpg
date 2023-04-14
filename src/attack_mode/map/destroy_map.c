/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_map.c
*/

#include "attack_mode.h"

void destroy_map(combat_map_t *map)
{
    for (int i = 0; i < map->height * map->width; i++) {
        destroy_tile(map->tiles[i]);
    }
    destroy_tile(map->far_tile);
    free(map);
}
