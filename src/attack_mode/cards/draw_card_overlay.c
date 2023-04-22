/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_card_overlay.c
*/

#include "attack_mode.h"

void draw_card_overlay(card_overlay_t *overlay, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, overlay->damage_sprite->sprite, NULL);
    sfRenderWindow_drawSprite(window, overlay->energy_sprite->sprite, NULL);
    sfRenderWindow_drawSprite(window, overlay->range_sprite->sprite, NULL);
    sfRenderWindow_drawText(window, overlay->name, NULL);
    sfRenderWindow_drawText(window, overlay->damage, NULL);
    sfRenderWindow_drawText(window, overlay->energy, NULL);
    sfRenderWindow_drawText(window, overlay->range, NULL);
}
