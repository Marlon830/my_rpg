/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_end_of_fight.c
*/

#include "attack_mode.h"

void update_end_of_fight(battle_scene_t *scene)
{
    if (scene->win == -2) {
        sfClock_restart(scene->clock);
        scene->win = -3;
    }
    if (scene->win == -3 && sfClock_getElapsedTime(scene->clock).microseconds
    / 1000000.0 > 1)
        scene->win = -1;
}
