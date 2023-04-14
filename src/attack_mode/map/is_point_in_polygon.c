/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** is_point_in_polygon.c
*/

#include "attack_mode.h"

int is_point_in_polygon(sfVector2f *polygon, int nb_points, sfVector2f point)
{
    int c = 0;
    int i, j, n = nb_points;
    for (i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > point.y) != (polygon[j].y > point.y)) &&
            (point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y)
            / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
                c = !c;
        }
    }
    return c;
}
