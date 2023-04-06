/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** is_point_in_diamond.c
*/

#include "attack_mode.h"

int is_point_in_diamond(sfVector2f point, tile_t *tile)
{
    sfVector2f *polygon = tile->points;
    int i, j, n = 4;
    int c = 0;
    for (i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > point.y) != (polygon[j].y > point.y)) &&
            (point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y)
            / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
                c = !c;
        }
    }
    return c;
}
