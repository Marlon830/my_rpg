/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_lazer.c
*/

#include "attack_mode.h"

void draw_lazer(lazer_t *lazer, sfRenderWindow *window)
{
    if (lazer->show)
        sfRenderWindow_drawVertexArray(window, lazer->array, NULL);
}
