/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_stats.c
*/

#include "project.h"

player_stats_t *init_stats(void)
{
    player_stats_t *player_stats = malloc(sizeof(*player_stats));

    player_stats->attack = 10;
    player_stats->defense = 10;
    player_stats->health = 10;
    player_stats->mana = 10;
    player_stats->move_range = 10;
    return player_stats;
}
