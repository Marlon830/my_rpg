/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_battle_scene_from_file.c
*/

#include "attack_mode.h"

void set_stats(project_t *project, battle_scene_t *scene)
{
    stat_t *actual_stats = scene->player->actual_stats;
    stat_t *real_stats = scene->player->basic_stats;
    player_stats_t *game_stats = project->player->player_stats;
    actual_stats->damage = game_stats->attack_value;
    real_stats->damage = game_stats->attack_value;
    actual_stats->health_point = game_stats->health_value;
    real_stats->health_point = game_stats->health_value;
    actual_stats->energy_points = game_stats->mana_value;
    real_stats->energy_points = game_stats->mana_value;
    actual_stats->move_points = game_stats->move_range_value;
    real_stats->move_points = game_stats->move_range_value;
}

battle_scene_t *create_battle_scene_from_file(char *filename, char *enemy_file,
project_t *project)
{
    battle_scene_t *res = malloc(sizeof(battle_scene_t));
    res->map = create_map_from_file(filename, (sfVector2f){100, 50});
    res->player = create_player(res->map->tiles[0]);
    res->hand = create_hand(1, res->player);
    res->nb_enemies = 0;
    res->win = 0;
    res->enemies = create_enemies_from_txt(enemy_file, res->map,
    &res->nb_enemies);
    res->player->tiles_close = get_tiles_close(res,
    res->player->actual_tile,
    res->player->actual_stats->move_points, res->player);
    res->view = sfView_create();
    res->hand->player = res->player;
    res->player->equipment = project->player->equipment;
    sfView_setSize(res->view, (sfVector2f){1920, 1080});
    sfView_setCenter(res->view, (sfVector2f){1920 / 2, 1080 / 2});
    set_stats(project, res);
    set_texture_equipment(res->player->equipment);
    return res;
}
