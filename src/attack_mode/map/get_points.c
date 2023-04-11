/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_points.c
*/

#include "attack_mode.h"

sfVector2f *get_points(tile_t *tile)
{
    sfVector2f *points = malloc(sizeof(sfVector2f) * 4);
    sfVector2f pos = tile->pos;
    sfVector2f size = tile->size;
    points[0] = (sfVector2f){pos.x - size.x / 2, pos.y};
    points[1] = (sfVector2f){pos.x, pos.y - size.y / 2};
    points[2] = (sfVector2f){pos.x + size.x / 2, pos.y};
    points[3] = (sfVector2f){pos.x, pos.y + size.y / 2};
    return points;
}
