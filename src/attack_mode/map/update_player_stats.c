/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_stats.c
*/

#include "attack_mode.h"

void update_player_stats(player_stats_t *stats, stat_t *actual_stats)
{
    stats->attack_value = actual_stats->damage;
    stats->health_value = actual_stats->health_point;
    stats->mana_value = actual_stats->energy_points;
    stats->move_range_value = actual_stats->move_points;
}
