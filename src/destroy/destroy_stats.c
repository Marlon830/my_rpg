/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_stats.c
*/

#include "project.h"

void destroy_stats(player_stats_t *player_stats)
{
    sfText_destroy(player_stats->health_name);
    sfText_destroy(player_stats->attack_name);
    sfText_destroy(player_stats->defense_name);
    sfText_destroy(player_stats->move_range_name);
    sfText_destroy(player_stats->mana_name);
    sfText_destroy(player_stats->health_text_value);
    sfText_destroy(player_stats->attack_text_value);
    sfText_destroy(player_stats->defense_text_value);
    sfText_destroy(player_stats->move_range_text_value);
    sfText_destroy(player_stats->mana_text_value);
    destroy_image(player_stats->health_image);
    destroy_image(player_stats->attack_image);
    destroy_image(player_stats->defense_image);
    destroy_image(player_stats->move_range_image);
    destroy_image(player_stats->mana_image);
    free(player_stats);
}
