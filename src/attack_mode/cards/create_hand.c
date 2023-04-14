/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** create_deck.c
*/

#include "attack_mode.h"

hand_t *create_hand(int nb_cards, combat_player_t *player)
{
    hand_t *res = malloc(sizeof(hand_t));
    res->cards = create_card("card", 10, 5, player);
    res->nb_cards = 1;
    for (int i = 1; i < nb_cards; i++) {
        add_card_to_hand(res, "card", 10, 10);
    }
    res->player = player;
    res->selected = NULL;
    return res;
}
