/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** draw_hand.c
*/

#include "attack_mode.h"

void draw_hand(hand_t *hand, sfRenderWindow *window)
{
    card_t *temp = hand->cards;
    for (int i = 0; i < hand->nb_cards; i++) {
        draw_card(temp, window);
        temp = temp->next;
    }
    if (hand->selected)
        draw_card(hand->selected, window);
}
