/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_card_overlay.c
*/

#include "attack_mode.h"

card_overlay_t *create_card_overlay(card_t *card)
{
    card_overlay_t *res = malloc(sizeof(card_overlay_t));
    res->damage = setup_text(int_to_str(card->damage), card->pos, 3);
    res->energy = setup_text(int_to_str(card->energy), card->pos, 3);
    res->range = setup_text(int_to_str(card->range), card->pos, 3);
    res->name = setup_text(card->name, card->pos, 3);
    res->sprite = sfSprite_create();
    return res;
}
