/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** add_cards_to_hand.c
*/

#include "attack_mode.h"

void add_card_to_hand(hand_t *hand, char *name, int damage, int range)
{
    card_t *temp = hand->cards;
    card_t *new_card = create_card(name, damage, range, hand->player);
    if (!temp) {
        hand->cards = new_card;
        hand->nb_cards += 1;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_card;
    new_card->previous = temp;
    hand->nb_cards += 1;
}
