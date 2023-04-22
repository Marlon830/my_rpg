/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_arrow.c
*/

#include "attack_mode.h"

void draw_arrow(arrow_t *arrow, sfRenderWindow *window)
{
    sfRenderWindow_drawVertexArray(window, arrow->array, NULL);
}
