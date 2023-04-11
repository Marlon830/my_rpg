/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-marlon.pegahi
** File description:
** change_height.c
*/

#include "attack_mode.h"

void change_height(float new_height, tile_t *tile)
{
    tile->pos.y += tile->height;
    tile->pos.y -= new_height;
    tile->height = new_height;
    sfVertexArray_clear(tile->array_tile);
    sfVertexArray_clear(tile->array_walls);
    create_tile_array(tile->pos, tile->color, tile->size, tile->array_tile);
    add_walls(tile);
    free(tile->points);
    tile->points = get_points(tile);
}
