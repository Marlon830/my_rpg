/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** end_of_turn.c
*/

#include "attack_mode.h"

void end_of_turn(combat_player_t *player, hand_t *hand)
{
    if (player->state != MOVING)
        return;
    srand(10);
    player->actual_stats->move_points = player->basic_stats->move_points;
    player->actual_stats->energy_points = player->basic_stats->energy_points;
    player->actual_stats->health_point += 10;
    for (int i = 0; i < 3; i++)
        if (hand->nb_cards < 12)
            add_card_to_hand(hand, "card", (rand() + 1) % 100,
            (rand() + 1) % 10 + 1);
}
