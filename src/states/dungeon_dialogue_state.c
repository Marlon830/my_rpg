/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** dialogue_state_bis.c
*/

#include "project.h"

void etchebest_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/etchebest.png")) {
        if (project->player->player_progress_state == 6) {
            project->status = FIGHT;
            project->pnj_fighting = act_pnj->name;
            project->battle_scene = create_battle_scene_from_file(
        "assets/fight_scene/etchebest_map.txt",
        "assets/fight_scene/etchebest_enemies.txt", project);
        }
    }
}

void heisenberg_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/heisenberg.png")) {
        if (project->player->player_progress_state == 8) {
            project->status = FIGHT;
            project->pnj_fighting = act_pnj->name;
            project->battle_scene = create_battle_scene_from_file(
        "assets/fight_scene/heisenberg_map.txt",
        "assets/fight_scene/heisenberg_enemies.txt", project);
        }
    }
}

void therock_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/therock.png")) {
        if (project->player->player_progress_state == 10) {
            project->status = FIGHT;
            project->pnj_fighting = act_pnj->name;
            project->battle_scene = create_battle_scene_from_file(
        "assets/fight_scene/therock_map.txt",
        "assets/fight_scene/therock_enemies.txt", project);
        }
    }
}

void creator_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/creator.png")) {
        if (project->player->player_progress_state == 14)
            start_credit(project);
        if (project->player->player_progress_state == 12) {
            project->player->player_progress_state = 13;
            set_pnj_dialogue(project->scene->pnj, "/creator.png", "Creator3");
            check_all_pnj_dialogue(project);
        }
        if (project->player->player_progress_state == 11)
            project->player->player_progress_state = 12;
        if (project->player->player_progress_state == 12) {
            set_pnj_dialogue(project->scene->pnj, "/creator.png", "Creator2");
            check_all_pnj_dialogue(project);
        }
    }
}
