/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** draw_card.c
*/

#include "attack_mode.h"

void draw_card(card_t *card, sfRenderWindow *window)
{
    sfRenderWindow_drawVertexArray(window, card->array, NULL);
    draw_card_overlay(card->overlay, window);
}
