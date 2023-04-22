/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** door_dialogue_state.c
*/

#include "project.h"

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

void dungeon_door2_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (project->player->player_progress_state == 10 &&
    !my_strcmp(act_pnj->name, "/door_boss2.png")) {
        project->player->pos.x = 48;
        project->player->pos.y = 416;
        project->player->col->left = project->player->pos.x + 11;
        project->player->col->top = project->player->pos.y + 16;
        project->scene = load_scene(project, 10);
    }
}

void dungeon_door3_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (project->player->player_progress_state == 11 &&
    !my_strcmp(act_pnj->name, "/door_boss3.png")) {
        project->player->pos.x = 80;
        project->player->pos.y = 128;
        project->player->col->left = project->player->pos.x + 11;
        project->player->col->top = project->player->pos.y + 16;
        project->scene = load_scene(project, 11);
        sfMusic_stop(project->main_menu->music_ingame);
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
        finish_quest("QUETE3", project->quests);
        add_quest("Chercher Mickey", project->quests, "SEC_QUETE1");
    }
}
