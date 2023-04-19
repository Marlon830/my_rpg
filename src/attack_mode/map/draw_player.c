/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** draw_player.c
*/

#include "attack_mode.h"

void draw_player(combat_player_t *player, sfRenderWindow *window)
{
    sfRenderWindow_drawVertexArray(window, player->array_character, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(window, player->overlay[i]->text, NULL);
    if (player->damage_taken->show)
        sfRenderWindow_drawText(window, player->damage_taken->text, NULL);
}
