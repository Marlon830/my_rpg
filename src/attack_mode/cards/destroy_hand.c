/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_hand.c
*/

#include "attack_mode.h"

void destroy_hand(hand_t *hand)
{
    card_t *c = hand->cards;
    while (hand->cards != NULL) {
        c = hand->cards;
        hand->cards = hand->cards->next;
        destroy_card(c);
    }
    free(hand);
}
