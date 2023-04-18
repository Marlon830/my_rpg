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

void set_angle(card_t *temp, float interval_angle, hand_t *hand, int i)
{
    temp->angle = -(hand->nb_cards * 10 > 60 ? 60 :
        hand->nb_cards * 10) / 2 + i * interval_angle;
}

void rotate_hand(hand_t *hand, sfVector2f mouse_pos)
{
    float p = hand->nb_cards * 50 > 1000 ? 1000 : hand->nb_cards * 50;
    float interval_angle = (hand->nb_cards *
    10 > 60 ? 60 : hand->nb_cards * 10) / (hand->nb_cards - 1);
    float mid_point = hand->nb_cards / 2.;
    sfVector2f new_pos;
    card_t *temp = hand->cards;
    for (int i = hand->nb_cards - 1; i >= 0; i--) {
        set_angle(temp, interval_angle, hand, i);
        new_pos.y = 60 * (i >= mid_point ?
        i / mid_point : (hand->nb_cards - i) / mid_point);
        new_pos.x = -p / 2 + i * p / (hand->nb_cards - 1) + 20;
        new_pos.y -= temp->state == HOVERED ? 100 : 0;
        move_card(temp, new_pos);
        if (temp->state == SELECTED) {
            temp->angle = 0;
            create_card_vertex(temp, mouse_pos);
        } else
            update_card_overlay(temp->overlay, temp);
        temp = temp->next;
    }
}

void update_hand(hand_t *hand, sfVector2f mouse_pos)
{
    reset_hand_pos(hand);
    card_t *temp = hand->cards;
    if (hand->nb_cards == 1) {
        if (temp->state == HOVERED) {
            move_card(temp, (sfVector2f){0, -100});
            update_card_overlay(temp->overlay, temp);
        }
        if (temp->state == SELECTED) {
            sfVertexArray_clear(temp->array);
            create_card_vertex(temp, mouse_pos);
        }
        return;
    }
    rotate_hand(hand, mouse_pos);
}
