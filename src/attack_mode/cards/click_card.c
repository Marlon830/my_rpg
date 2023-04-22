/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** click_card.c
*/

#include "attack_mode.h"

void remove_from_linked_list(card_t *temp, hand_t *hand)
{
    if (temp->next) {
        temp->next->previous = temp->previous;
    }
    if (temp->previous) {
        temp->previous->next = temp->next;
    } else if (temp->next)
        hand->cards = temp->next;
    if (temp->next || temp->previous)
        hand->nb_cards -= 1;
    else {
        hand->cards = NULL;
        hand->nb_cards -= 1;
    }
}

void unclick_card(hand_t *hand, battle_scene_t *scene)
{
    card_t *temp = hand->cards;
    while (temp != NULL) {
        if (temp->state == SELECTED) {
            hand->selected = NULL;
            temp->state = NOTHING;
            scene->player->state = ATTACKING;
            scene->player->attack_tiles =
            update_attack_tiles(scene->player, temp, scene);
            scene->player->card = temp;
            remove_from_linked_list(temp, hand);
            return;
        }
        temp = temp->next;
    }
}

void set_card2(card_state *temp_state,
card_t *temp, sfVector2f **points)
{
    *temp_state = temp->state;
    *points = get_all_vector_from_vertex(temp->array);
}

void set_card(sfRenderWindow *window, sfEvent event, hand_t *hand)
{
    card_t *temp = hand->cards;
    sfVector2f *points = get_all_vector_from_vertex(temp->array);
    int nb_points = sfVertexArray_getVertexCount(temp->array) - 4;
    int ok = 0;
    card_state temp_state = NOTHING;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        set_card2(&temp_state, temp, &points);
        if (!ok && is_point_in_polygon(points, nb_points,
        (sfVector2f) convert_mouse_window(window, event.mouseButton.x,
        event.mouseButton.y))
        && temp->energy <= hand->player->actual_stats->energy_points) {
            temp->state = SELECTED;
            ok = 1;
            hand->selected = temp;
        } else
            temp->state = temp_state;
        temp = temp->previous;
    }
}

void click_card(sfRenderWindow *window, sfEvent event, hand_t *hand)
{
    if (hand->player->actual_stats->energy_points <= 0)
        return;
    if (event.mouseButton.button == sfMouseRight
    && hand->player->state == ATTACKING) {
        add_card_to_hand(hand, hand->player->card->name,
        hand->player->card->damage, hand->player->card->range);
        free(hand->player->card);
        hand->player->state = MOVING;
        hand->player->card = NULL;
        return;
    }
    card_t *temp = hand->cards;
    if (!temp || hand->player->card)
        return;
    set_card(window, event, hand);
}
