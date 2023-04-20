/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** upscale_player_stats.c
*/

#include "attack_mode.h"

void upscale_player_stats(player_stats_t *stats, sfVector2f scale)
{
    sfText_setScale(stats->attack_name, scale);
    sfText_setScale(stats->defense_name, scale);
    sfText_setScale(stats->health_name, scale);
    sfText_setScale(stats->move_range_name, scale);
    sfText_setScale(stats->mana_name, scale);
    sfText_setScale(stats->attack_text_value, scale);
    sfText_setScale(stats->defense_text_value, scale);
    sfText_setScale(stats->health_text_value, scale);
    sfText_setScale(stats->move_range_text_value, scale);
    sfText_setScale(stats->mana_text_value, scale);
}
