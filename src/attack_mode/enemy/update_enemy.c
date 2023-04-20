/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_enemy.c
*/

#include "attack_mode.h"

void update_enemies(enemy_t **enemies, int nb_enemies, battle_scene_t *scene)
{
    int b = 0;
    for (int i = 0; i < nb_enemies; i++) {
        sfSprite_setPosition(enemies[i]->sprite->sprite,
        enemies[i]->actual_tile->pos);
        enemies[i]->tiles_close = get_enemy_tiles_close(scene,enemies[i]
        ->actual_tile, enemies[i]->actual_stats->move_points, enemies[i]);
        if (enemies[i] != NULL)
            update_damage_taken(enemies[i]->damage_taken);
        if (enemies[i] != NULL && enemies[i]->actual_stats->health_point
        <= 0 && !enemies[i]->damage_taken->show) {
            free(enemies[i]);
            enemies[i] = NULL;
        }
    }
    for (int i = 0; i < nb_enemies; i++) {
        if (enemies[i] != NULL)
            b = 1;
    }
    if (!b)
        scene->win = 1;
}
