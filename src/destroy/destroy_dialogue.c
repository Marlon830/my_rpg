/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_dialogue.c
*/

#include "project.h"

void destroy_dialogue(act_dial_t *actual_dial)
{
    if (actual_dial == NULL)
        return;
    if (actual_dial->dialogue != NULL)
        free(actual_dial->dialogue);
    if (actual_dial->face != NULL)
        destroy_image(actual_dial->face);
    if (actual_dial->rect != NULL)
        sfRectangleShape_destroy(actual_dial->rect);
    if (actual_dial->text != NULL)
        sfText_destroy(actual_dial->text);
    free(actual_dial);
}
