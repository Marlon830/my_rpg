/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** dialogue_state.c
*/

#include "project.h"

void theoronfle_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (project->player->player_progress_state == 0 &&
    !my_strcmp(act_pnj->name, "/theodore.png"))
        project->player->player_progress_state = 1;
    if ((project->player->player_progress_state == 2 ||
    project->player->player_progress_state == 3) &&
    !my_strcmp(act_pnj->name, "/theodore.png")) {
        project->status = FIGHT;
        project->pnj_fighting = act_pnj->name;
        project->battle_scene = create_battle_scene_from_file(
    "assets/fight_scene/theoronfle_map.txt",
    "assets/fight_scene/theoronfle_enemies.txt", project);
    }
}

void bed_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/bed.png")) {
        project->status = FIGHT;
        project->pnj_fighting = act_pnj->name;
        project->battle_scene = create_battle_scene_from_file(
    "assets/fight_scene/bed_map.txt",
    "assets/fight_scene/bed_enemies.txt", project);
    }
}

void skull_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (project->player->player_progress_state == 4 &&
    !my_strcmp(act_pnj->name, "/skull.png")) {
        project->status = FIGHT;
        project->pnj_fighting = act_pnj->name;
        project->battle_scene = create_battle_scene_from_file(
    "assets/fight_scene/skull_map.txt",
    "assets/fight_scene/skull_enemies.txt", project);
    }
}
