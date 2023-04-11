/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** create_stats.c
*/

#include "attack_mode.h"

stat_t *create_stats(void)
{
    stat_t *res = malloc(sizeof(stat_t));
    res->damage = 10;
    res->health_point = 100;
    res->move_points = 10;
    return res;
}
