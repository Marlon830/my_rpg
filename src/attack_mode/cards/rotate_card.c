/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** rotate_card.c
*/

#include "attack_mode.h"

void add_pos(sfVector2f pos, sfVector2f *point)
{
    point->x -= pos.x;
    point->y -= pos.y;
}

void rotate(sfVector2f *point, float angle)
{
    sfVector2f temp = *point;
    point->x = temp.x * cos(angle) - temp.y * sin(angle);
    point->y = temp.x * sin(angle) + temp.y * cos(angle);
}

void rotate_card(card_t *card, float angle)
{
    angle = angle * PI / 180.;
    sfVector2f point;
    for (int i = 0; i < 8; i++) {
        point = sfVertexArray_getVertex(card->array, i)->position;
        add_pos(card->pos, &point);
        rotate(&point, angle);
        add_pos((sfVector2f){-card->pos.x, -card->pos.y}, &point);
        sfVertexArray_getVertex(card->array, i)->position = point;
    }
}
