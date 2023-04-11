/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** update_player.c
*/

#include "attack_mode.h"

void update_player(player_t *player)
{
    sfVertexArray_clear(player->array_character);
    set_player_pos(player);
}
