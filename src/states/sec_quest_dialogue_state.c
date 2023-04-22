/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** sec_quest_dialogue_state.c
*/

#include "project.h"

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

void kid_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/kid.png")) {
        if (project->player->player_second_state == 2) {
            project->status = FIGHT;
            project->pnj_fighting = act_pnj->name;
            project->battle_scene = create_battle_scene_from_file(
        "assets/fight_scene/kid_map.txt",
        "assets/fight_scene/kid_enemies.txt", project);
        }
    }
}

void boat_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/boat_guy.png")) {
        if (project->player->player_second_state == 3) {
            project->status = FIGHT;
            project->pnj_fighting = act_pnj->name;
            project->battle_scene = create_battle_scene_from_file(
        "assets/fight_scene/boat_map.txt",
        "assets/fight_scene/boat_enemies.txt", project);
        }
    }
}
