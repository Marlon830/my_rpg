/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_card_overlay.c
*/

#include "attack_mode.h"

void destroy_card_overlay(card_overlay_t *overlay)
{
    sfText_destroy(overlay->damage);
    sfText_destroy(overlay->energy);
    sfText_destroy(overlay->name);
    sfText_destroy(overlay->range);
    sfSprite_destroy(overlay->sprite);
    free(overlay);
}
