/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** is_there_an_enemy.c
*/


#include "attack_mode.h"

int is_there_an_enemy(tile_t *tile, enemy_t **enemies, int nb_enemies)
{
    for (int i = 0; i < nb_enemies; i++) {
        if (tile->ind == enemies[i]->actual_tile->ind)
            return 1;
    }
    return 0;
}
