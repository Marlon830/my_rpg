/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_enemy.c
*/

#include "attack_mode.h"

void update_enemies(enemy_t **enemies, int nb_enemies)
{
    for (int i = 0; i < nb_enemies; i++) {
        if (enemies[i] != NULL)
            update_damage_taken(enemies[i]->damage_taken);
        if (enemies[i] != NULL && enemies[i]->actual_stats->health_point <= 0) {
            free(enemies[i]);
            enemies[i] = NULL;
        }
    }
}
