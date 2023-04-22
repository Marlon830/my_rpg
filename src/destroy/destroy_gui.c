/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_gui.c
*/

#include "project.h"

void destroy_button(button_t *button)
{
    if (button == NULL)
        return;
    if (button->rect != NULL)
        sfRectangleShape_destroy(button->rect);
    if (button->sprite != NULL)
        sfSprite_destroy(button->sprite);
    if (button->texture != NULL)
        sfTexture_destroy(button->texture);
    if (button->texture_hover != NULL)
        sfTexture_destroy(button->texture_hover);
    free(button);
}

void destroy_slider(slider_t *slider)
{
    if (slider == NULL)
        return;
    if (slider->circle != NULL)
        sfCircleShape_destroy(slider->circle);
    if (slider->rect != NULL)
        sfRectangleShape_destroy(slider->rect);
    free(slider);
}
