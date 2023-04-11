/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** update_hand.c
*/

#include "attack_mode.h"

void reset_hand_pos(hand_t *hand)
{
    card_t *temp = hand->cards;
    for (int i = 0; i < hand->nb_cards; i++) {
        sfVertexArray_clear(temp->array);
        create_card_vertex(temp, temp->pos);
        temp = temp->next;
    }
}

void update_hand(hand_t *hand)
{
    reset_hand_pos(hand);
    if (hand->nb_cards == 1)
        return;
    float p = hand->nb_cards * 50 > 1000 ? 1000 : hand->nb_cards * 50;
    float interval_angle = 45 / (hand->nb_cards - 1);
    float interval_x = p / (hand->nb_cards - 1);
    float mid_point = hand->nb_cards / 2.;
    float angle = 0;
    sfVector2f new_pos;
    card_t *temp = hand->cards;
    new_pos.y = 0;
    for (int i = hand->nb_cards - 1; i >= 0; i--) {
        angle = -45 / 2 + i * interval_angle;
        new_pos.y = 60 * (i >= mid_point ?
        i / mid_point : (hand->nb_cards - i) / mid_point) ;
        new_pos.x = -p / 2 + i * interval_x + 20;
        rotate_card(temp, angle);
        move_card(temp, new_pos);
        temp = temp->next;
    }
}
