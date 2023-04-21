/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_lazer.c
*/

#include "attack_mode.h"

void update_lazer(lazer_t *lazer)
{
    if (lazer->show == 1) {
        sfClock_restart(lazer->clock);
        lazer->show = 2;
    }
    if (sfClock_getElapsedTime(lazer->clock).microseconds / 1000000.0 > .5)
        lazer->show = 0;
}
