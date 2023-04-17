/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_tile.c
*/

#include "attack_mode.h"

void destroy_tile(tile_t *tile)
{
    sfVertexArray_destroy(tile->array_tile);
    sfVertexArray_destroy(tile->array_walls);
    free(tile->points);
    free(tile);
}
