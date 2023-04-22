/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** change_dialogue_bis.c
*/

#include "project.h"

void change_state_with_dialogue(project_t *project, all_pnjs_t *act_pnj)
{
    theoronfle_quest(project, act_pnj);
    bed_quest(project, act_pnj);
    skull_quest(project, act_pnj);
    door_quest(project, act_pnj);
    chest_quest(project, act_pnj);
    etchebest_quest(project, act_pnj);
    mickey_quest(project, act_pnj);
    client_quest(project, act_pnj);
    kid_quest(project, act_pnj);
    dungeon_door1_quest(project, act_pnj);
    dungeon_door2_quest(project, act_pnj);
    dungeon_door3_quest(project, act_pnj);
    heisenberg_quest(project, act_pnj);
    chest2_quest(project, act_pnj);
    therock_quest(project, act_pnj);
    boat_quest(project, act_pnj);
    creator_quest(project, act_pnj);
}

void change_state_with_scene(project_t *project, int to_scene_id)
{
    if (project->player->player_progress_state == 0 && to_scene_id == HOUSE)
        project->player->player_progress_state = 3;
    if (project->player->player_progress_state == 1 && to_scene_id == HOUSE)
        project->player->player_progress_state = 2;
}
