/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** hover_card.c
*/

#include "attack_mode.h"

void hover_card(sfEvent event, hand_t *hand)
{
    card_t *temp = hand->cards;
    if (!temp)
        return;
    sfVector2f *points = get_all_vector_from_vertex(temp->array);
    int nb_points = sfVertexArray_getVertexCount(temp->array) - 4;
    card_state temp_state = NONE;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        temp_state = temp->state == HOVERED ? NONE : temp->state;
        points = get_all_vector_from_vertex(temp->array);
        if (temp->state != HOVERED && is_point_in_polygon(points, nb_points,
        (sfVector2f){event.mouseMove.x, event.mouseMove.y})
        && temp->state != SELECTED)
            temp->state = HOVERED;
        else
            temp->state = temp_state;
        temp = temp->previous;
    }
}
