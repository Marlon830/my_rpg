/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** update_player.c
*/

#include "attack_mode.h"

void update_player(combat_player_t *player)
{
    sfVertexArray_clear(player->array_character);
    if (player->actual_stats->energy_points < 0)
        player->actual_stats->energy_points = 0;
    set_player_pos(player);
}
