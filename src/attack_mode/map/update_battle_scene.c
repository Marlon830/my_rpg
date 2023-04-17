/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** update_scene.c
*/

#include "attack_mode.h"

void update_battle_scene(battle_scene_t *scene,
__attribute__((unused))float time, sfRenderWindow *window)
{
        if (scene->player->state == MOVING)
                scene->player->tiles_close =
        update_tiles_close(scene->player, scene->map,
        scene->player->actual_tile, scene->player->actual_stats->move_points);
        update_player(scene->player);
        color_tiles(scene->map, scene->player);
        update_hand(scene->hand, (sfVector2f)
        {sfMouse_getPositionRenderWindow(window).x,
        sfMouse_getPositionRenderWindow(window).y});
        update_enemies(scene->enemies, scene->nb_enemies, scene);
        for (int i = 0; i < scene->nb_enemies; i++) {
                if (scene->enemies[i] != NULL) {
                        change_enemy_color(scene->enemies[i]);
                }
        }
        draw_batle_scene(scene, window);
}
