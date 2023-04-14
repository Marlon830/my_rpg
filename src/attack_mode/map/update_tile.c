/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_tile.c
*/

#include "attack_mode.h"

void update_tile(tile_t *tile)
{
    int nb_tiles = sfVertexArray_getVertexCount(tile->array_tile);
    for (int i = 0; i < nb_tiles; i++) {
        sfVertexArray_getVertex(tile->array_tile, i)->color = tile->color;
    }
}
