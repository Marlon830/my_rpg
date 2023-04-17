/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** change_color.c
*/

#include "attack_mode.h"

void change_enemy_color(enemy_t *enemy)
{
    int nb_vertex = sfVertexArray_getVertexCount(enemy->array_character);
    float ratio = enemy->actual_stats->health_point /
    enemy->basic_stats->health_point;
    for (int i = 0; i < nb_vertex; i++) {
        sfVertexArray_getVertex(enemy->array_character, i)->color =
        (sfColor){(ratio * 255), 0, 0, 255};
    }
}
