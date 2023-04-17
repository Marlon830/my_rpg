/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** manhattan_dist.c
*/

#include "attack_mode.h"

float manhattan_dist(sfVector2f p1, sfVector2f p2)
{
    return fabs(p1.x - p2.x) + fabs(p1.y - p2.y);
}
