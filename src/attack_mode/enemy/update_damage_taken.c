/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** show_damage_taken.c
*/

#include "attack_mode.h"

void update_damage_taken(combat_text_t *text)
{
    if (text->show == 1) {
        sfClock_restart(text->clock);
        text->show = 2;
    }
    if (sfClock_getElapsedTime(text->clock).microseconds / 1000000.0 > .5)
        text->show = 0;
}
