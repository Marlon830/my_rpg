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
        finish_quest("QUETE1", project->quests);
        add_quest("Visiter les environs", project->quests, "QUETE2");
        project->status = FIGHT;
        project->pnj_fighting = act_pnj->name;
        project->battle_scene = create_battle_scene_from_file(
    "assets/fight_scene/theoronfle_map.txt",
    "assets/fight_scene/theoronfle_enemies.txt");
    }
}

void bed_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/bed.png")) {
        project->status = FIGHT;
        project->battle_scene = create_battle_scene_from_file(
    "assets/fight_scene/bed_map.txt",
    "assets/fight_scene/bed_enemies.txt");
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
    "assets/fight_scene/skull_enemies.txt");
    }
}

void door_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (project->player->player_progress_state == 5 &&
    !my_strcmp(act_pnj->name, "/door.png")) {
        project->player->player_progress_state = 6;
        project->player->pos.x = 1664;
        project->player->pos.y = 416;
        project->player->col->left = project->player->pos.x + 11;
        project->player->col->top = project->player->pos.y + 16;
        project->scene = load_scene(project, 3);
    }
}
