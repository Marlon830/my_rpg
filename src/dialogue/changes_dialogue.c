/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** changes_dialogue.c
*/

#include "project.h"

void change_state_with_dialogue(project_t *project)
{
    if (project->player->player_progress_state == 2) {
        finish_quest("QUETE1", project->quests);
        project->status = FIGHT;
    }
    if (project->player->player_progress_state == 0)
        project->player->player_progress_state = 1;
}

void change_state_with_scene(project_t *project)
{
    if (project->player->player_progress_state == 0)
        project->player->player_progress_state = 3;
    if (project->player->player_progress_state == 1)
        project->player->player_progress_state = 2;
}

void set_all_pnj_dialogues(project_t *project)
{
    set_pnj_dialogue(project->scene->pnj, "/door.png", "Dungeon1");
    set_pnj_dialogue(project->scene->pnj, "/bed.png", "Bed");
    if (project->player->player_progress_state == 0)
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle");
    if (project->player->player_progress_state == 1) {
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle2");
        add_quest("Trouver la batterie de theodore", project->quests, "QUETE1");
    }
    if (project->player->player_progress_state == 2)
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle3");
    if (project->player->player_progress_state == 3)
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle4");
}
