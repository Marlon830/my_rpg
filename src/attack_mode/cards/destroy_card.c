/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_card.c
*/

#include "attack_mode.h"

void destroy_card(card_t *card)
{
    sfVertexArray_destroy(card->array);
    destroy_card_overlay(card->overlay);
    free(card);
}
