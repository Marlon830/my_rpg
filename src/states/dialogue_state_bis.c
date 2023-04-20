/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** dialogue_state_bis.c
*/

#include "project.h"

void chest_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/chest.png")) {
        if (project->player->player_progress_state == 7) {
            add_elem(project->inventory->bag, "assets/object/helmet_gold.png",
            HELMET, 1);
            project->player->player_progress_state = 8;
        }
    }
}

void enemy1_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/enemy.png")) {
        if (project->player->player_progress_state == 6) {
            project->status = FIGHT;
            project->pnj_fighting = act_pnj->name;
            project->battle_scene = create_battle_scene_from_file(
        "assets/fight_scene/etchebest_map.txt",
        "assets/fight_scene/etchebest_enemies.txt");
        }
    }
}
