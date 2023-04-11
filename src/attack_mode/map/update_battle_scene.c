/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** update_scene.c
*/

#include "attack_mode.h"

void update_battle_scene(battle_scene_t *scene, float time)
{
        scene->player->tiles_close =
        update_tiles_close(scene->player, scene->map,
        scene->player->actual_tile, scene->player->actual_stats->move_points);
        update_player(scene->player);
        color_tiles(scene->map, scene->player);
}
