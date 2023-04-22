/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_lazer.c
*/

#include "attack_mode.h"

void destroy_lazer(lazer_t *lazer)
{
    sfVertexArray_destroy(lazer->array);
    sfClock_destroy(lazer->clock);
    free(lazer);
}
