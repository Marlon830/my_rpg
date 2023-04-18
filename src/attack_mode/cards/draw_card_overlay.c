/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_card_overlay.c
*/

#include "attack_mode.h"

void draw_card_overlay(card_overlay_t *overlay, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, overlay->name, NULL);
    sfRenderWindow_drawText(window, overlay->damage, NULL);
    sfRenderWindow_drawText(window, overlay->energy, NULL);
    sfRenderWindow_drawText(window, overlay->range, NULL);
}
