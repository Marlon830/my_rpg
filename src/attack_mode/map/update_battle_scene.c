/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** update_scene.c
*/

#include "attack_mode.h"

void update_battle_scene(battle_scene_t *scene, project_t *project,
sfRenderWindow *window)
{
        if (scene->player->state == MOVING)
                scene->player->tiles_close =
        update_tiles_close(scene->player, scene,
        scene->player->actual_tile, scene->player->actual_stats->move_points);
        update_player(scene->player, scene);
        color_tiles(scene->map, scene->player);
        update_hand(scene->hand, (sfVector2f)
        {sfMouse_getPositionRenderWindow(window).x,
        sfMouse_getPositionRenderWindow(window).y});
        update_enemies(scene->enemies, scene->nb_enemies, scene);
        update_player_stats(project->player->player_stats,
        scene->player->actual_stats);
        draw_batle_scene(scene, window, project);
        update_lazer(scene->lazer);
        update_black_fade(scene);
        update_end_of_fight(scene);
}
