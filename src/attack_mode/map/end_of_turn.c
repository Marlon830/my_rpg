/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** end_of_turn.c
*/

#include "attack_mode.h"

void end_of_turn(player_t *player, hand_t *hand)
{
    player->actual_stats->move_points = player->basic_stats->move_points;
    player->actual_stats->health_point += 10;
    add_card_to_hand(hand, "card", 10, 5);
}
