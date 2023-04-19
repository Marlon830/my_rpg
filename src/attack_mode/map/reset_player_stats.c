/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** reset_player_stats.c
*/

#include "attack_mode.h"

void set_player_stats(combat_player_t *player)
{
    player->actual_stats->move_points = player->basic_stats->move_points;
    player->actual_stats->energy_points = player->basic_stats->energy_points;
    if (player->actual_stats->health_point >=
    player->basic_stats->health_point)
        player->actual_stats->health_point = player->basic_stats->health_point;
    if (player->actual_stats->health_point <= 0)
        player->actual_stats->health_point = 0;
}
