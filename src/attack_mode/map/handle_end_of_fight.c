/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handle_end_of_fight.c
*/

#include "attack_mode.h"
#include "project.h"

void handle_end_of_fight(project_t *project)
{
    project->fight_win = project->battle_scene->win;
    if (project->battle_scene->win) {
        upscale_player_stats(project->player->player_stats,
        (sfVector2f){.08, .08});
        update_player_stats(project->player->player_stats,
        project->battle_scene->player->basic_stats);
        destroy_battle_scene(project->battle_scene);
        project->battle_scene = NULL;
        project->status = GAME;
        project->scene = load_scene(project, project->scene_id);
        set_state_with_end_of_fight(project);
    }
}
