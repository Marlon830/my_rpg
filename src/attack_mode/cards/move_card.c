/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** move_card.c
*/

#include "attack_mode.h"

void move_card(card_t *card, sfVector2f increment)
{
    rotate_card(card, card->angle);
    sfVector2f *p;
    for (int i = 0; i < 8; i++) {
        p = &sfVertexArray_getVertex(card->array, i)->position;
        p->x += increment.x;
        p->y += increment.y;
    }
}
