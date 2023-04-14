/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_battle_scene.c
*/

#include "attack_mode.h"

void destroy_battle_scene(battle_scene_t *scene)
{
    destroy_player(scene->player);
    for (int i = 0; i < scene->nb_enemies; i++)
        destroy_enemy(scene->enemies[i]);
    destroy_map(scene->map);
    destroy_hand(scene->hand);
    free(scene);
    return;
}
