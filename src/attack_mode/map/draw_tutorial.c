/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_tutorial.c
*/

#include "attack_mode.h"

void draw_tutorial(tutorial_t *tutorial, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, tutorial->left_click->sprite, NULL);
    sfRenderWindow_drawSprite(window, tutorial->right_click->sprite, NULL);
    sfRenderWindow_drawSprite(window, tutorial->space_bar->sprite, NULL);
    sfRenderWindow_drawText(window, tutorial->left_click_text, NULL);
    sfRenderWindow_drawText(window, tutorial->right_click_text, NULL);
    sfRenderWindow_drawText(window, tutorial->space_bar_text, NULL);
}
