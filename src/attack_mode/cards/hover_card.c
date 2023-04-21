/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** hover_card.c
*/

#include "attack_mode.h"

void hover_card2(card_state *temp_state,
card_t *temp, sfVector2f **points)
{
    *temp_state = temp->state == HOVERED ? NOTHING : temp->state;
    *points = get_all_vector_from_vertex(temp->array);
}

void hover_card(sfRenderWindow *window, sfEvent event, hand_t *hand)
{
    card_t *temp = hand->cards;
    if (!temp)
        return;
    sfVector2f *points = get_all_vector_from_vertex(temp->array);
    int nb_points = sfVertexArray_getVertexCount(temp->array) - 4;
    int ok = 0;
    card_state temp_state = NOTHING;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        hover_card2(&temp_state, temp, &points);
        if (!ok && is_point_in_polygon(points, nb_points, (sfVector2f)
        convert_mouse_window(window, event.mouseMove.x, event.mouseMove.y))
        && temp->state != SELECTED) {
            temp->state = HOVERED;
            ok = 1;
        } else
            temp->state = temp_state;
        temp = temp->previous;
    }
}
