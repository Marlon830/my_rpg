/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** draw_player.c
*/

#include "attack_mode.h"

void draw_player(player_t *player, sfRenderWindow *window)
{
    sfRenderWindow_drawVertexArray(window, player->array_character, NULL);
}
