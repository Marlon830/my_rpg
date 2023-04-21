/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** dialogue_state_ter.c
*/

#include "project.h"

void squest_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/enemy_sq1.png")) {
        if (project->player->player_second_state == 2) {
            project->status = FIGHT;
            project->pnj_fighting = act_pnj->name;
            project->battle_scene = create_battle_scene_from_file(
        "assets/fight_scene/squest_map.txt",
        "assets/fight_scene/squest_enemies.txt", project);
        }
    }
}
