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
        "assets/fight_scene/etchebest_enemies.txt", project);
        }
    }
}

void mickey_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/mickey.png")) {
        if (project->player->player_second_state == 0) {
            project->status = FIGHT;
            project->pnj_fighting = act_pnj->name;
            project->battle_scene = create_battle_scene_from_file(
        "assets/fight_scene/mickey_map.txt",
        "assets/fight_scene/mickey_enemies.txt", project);
        }
    }
}

void client_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/client.png")) {
        if (project->player->player_second_state == 1) {
            project->status = FIGHT;
            project->pnj_fighting = act_pnj->name;
            project->battle_scene = create_battle_scene_from_file(
        "assets/fight_scene/client_map.txt",
        "assets/fight_scene/client_enemies.txt", project);
        }
    }
}

void dungeon_door1_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (project->player->player_progress_state == 8 &&
    !my_strcmp(act_pnj->name, "/door_boss1.png")) {
        project->player->pos.x = 48;
        project->player->pos.y = 416;
        project->player->col->left = project->player->pos.x + 11;
        project->player->col->top = project->player->pos.y + 16;
        project->scene = load_scene(project, 9);
    }
}
