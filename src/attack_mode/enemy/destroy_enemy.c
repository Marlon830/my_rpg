/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_enemy.c
*/

#include "attack_mode.h"

void destroy_enemy(enemy_t *enemy)
{
    if (enemy == NULL)
        return;
    free(enemy->basic_stats);
    free(enemy->actual_stats);
    sfVertexArray_destroy(enemy->array_character);
    destroy_combat_text(enemy->damage_taken);
    destroy_image(enemy->sprite);
    free(enemy);
}
