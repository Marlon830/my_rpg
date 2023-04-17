/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-marlon.pegahi
** File description:
** add_walls.c
*/

#include "attack_mode.h"

void add_walls_left(tile_t *tile)
{
    sfVertex p1 = vertex_create(tile->points[0], (sfColor){134, 135, 132, 255});
    sfVertex p2 = vertex_create(tile->points[3], (sfColor){134, 135, 132, 255});
    sfVertex p3 = vertex_create((sfVector2f){tile->points[3].x,
    tile->points[3].y + tile->height}, (sfColor){134, 135, 132, 255});
    sfVertex p4 = vertex_create((sfVector2f){tile->points[0].x,
    tile->points[0].y + tile->height}, (sfColor){134, 135, 132, 255});
    sfVertexArray_append(tile->array_walls, p1);
    sfVertexArray_append(tile->array_walls, p2);
    sfVertexArray_append(tile->array_walls, p3);
    sfVertexArray_append(tile->array_walls, p4);
}

void add_walls_right(tile_t *tile)
{
    sfVertex p1 = vertex_create(tile->points[3], (sfColor){28, 48, 65, 255});
    sfVertex p2 = vertex_create(tile->points[2], (sfColor){28, 48, 65, 255});
    sfVertex p3 = vertex_create((sfVector2f){tile->points[2].x,
    tile->points[2].y + tile->height}, (sfColor){28, 48, 65, 255});
    sfVertex p4 = vertex_create((sfVector2f){tile->points[3].x,
    tile->points[3].y + tile->height}, (sfColor){28, 48, 65, 255});
    sfVertexArray_append(tile->array_walls, p1);
    sfVertexArray_append(tile->array_walls, p2);
    sfVertexArray_append(tile->array_walls, p3);
    sfVertexArray_append(tile->array_walls, p4);
}

void add_walls(tile_t *tile)
{
    add_walls_left(tile);
    add_walls_right(tile);
}
