/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_player.c
*/

#include "attack_mode.h"

void destroy_player(combat_player_t *player)
{
    free(player->actual_stats);
    sfVertexArray_destroy(player->array_character);
    free(player->basic_stats);
    free(player);
}