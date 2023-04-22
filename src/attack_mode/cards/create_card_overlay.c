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
    res->damage_sprite = create_sprite("assets/object/sword_silver.png",
    card->pos);
    sfSprite_setScale(res->damage_sprite->sprite, (sfVector2f){2, 2});
    res->energy_sprite = create_sprite("assets/stats/mana.png", card->pos);
    sfSprite_setScale(res->energy_sprite->sprite, (sfVector2f){2, 2});
    res->range_sprite = create_sprite("assets/object/boots_silver.png",
    card->pos);
    sfSprite_setScale(res->range_sprite->sprite, (sfVector2f){2, 2});
    return res;
}
