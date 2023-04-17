/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_tile.c
*/

#include "attack_mode.h"

void create_tile_array(sfVector2f center, sfColor color,
sfVector2f size, sfVertexArray *tile)
{
    sfVertex p1 = vertex_create((sfVector2f)
    {center.x - size.x / 2, center.y }, color);
    sfVertex p2 = vertex_create((sfVector2f)
    {center.x, center.y - size.y / 2}, color);
    sfVertex p3 = vertex_create((sfVector2f)
    {center.x + size.x / 2, center.y}, color);
    sfVertex p4 = vertex_create((sfVector2f)
    {center.x, center.y + size.y / 2}, color);
    sfVertexArray_append(tile, p1);
    sfVertexArray_append(tile, p2);
    sfVertexArray_append(tile, p3);
    sfVertexArray_append(tile, p4);
}

tile_t *create_tile(sfVector2f center, sfColor color,
sfVector2f size, float height)
{
    tile_t *res = malloc(sizeof(tile_t));
    center.y -= height;
    res->height = height;
    res->array_tile = sfVertexArray_create();
    create_tile_array(center, color, size, res->array_tile);
    res->array_walls = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(res->array_tile, sfQuads);
    sfVertexArray_setPrimitiveType(res->array_walls, sfQuads);
    res->color = color;
    res->pos = center;
    res->size = size;
    res->points = get_points(res);
    add_walls(res);
    return res;
}
