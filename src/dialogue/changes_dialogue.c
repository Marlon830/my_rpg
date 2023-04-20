/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** changes_dialogue.c
*/

#include "project.h"

void set_state_with_end_of_fight(project_t *project)
{
    if (project->fight_win == 1) {
        if (!my_strcmp("/theodore.png", project->pnj_fighting)) {
            project->player->player_progress_state = 4;
            add_elem(project->inventory->bag, "assets/object/pants_bronze.png",
            PANTS, 1);
            set_pnj_dialogue(project->scene->pnj, "/theodore.png",
            "Theoronfle5");
            check_all_pnj_dialogue(project);
        }
        if (!my_strcmp("/skull.png", project->pnj_fighting)) {
            project->player->player_progress_state = 5;
            finish_quest("QUETE2", project->quests);
            add_quest("Aller au salon de coiffure en ville", project->quests,
            "QUETE3");
            add_elem(project->inventory->bag,
            "assets/object/sword_bronze.png", SWORD, 1);
            set_pnj_dialogue(project->scene->pnj, "/skull.png", "Skull3");
            check_all_pnj_dialogue(project);
        }
    }
}

void change_state_with_dialogue(project_t *project, all_pnjs_t *act_pnj)
{
    theoronfle_quest(project, act_pnj);
    bed_quest(project, act_pnj);
    skull_quest(project, act_pnj);
    door_quest(project, act_pnj);
}

void change_state_with_scene(project_t *project, int to_scene_id)
{
    if (project->player->player_progress_state == 0 && to_scene_id == HOUSE)
        project->player->player_progress_state = 3;
    if (project->player->player_progress_state == 1 && to_scene_id == HOUSE)
        project->player->player_progress_state = 2;
}

void set_all_pnj_dialogues_bis(project_t *project)
{
    if (project->player->player_progress_state >= 3)
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle4");
    if (project->player->player_progress_state >= 4) {
        set_pnj_dialogue(project->scene->pnj, "/skull.png", "Skull2");
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle5");
    }
    if (project->player->player_progress_state >= 5) {
        set_pnj_dialogue(project->scene->pnj, "/door.png", "Dungeon2");
        set_pnj_dialogue(project->scene->pnj, "/skull.png", "Skull3");
    }
}

void set_all_pnj_dialogues(project_t *project)
{
    if (project->player->player_progress_state >= 0) {
        set_pnj_dialogue(project->scene->pnj, "/door.png", "Dungeon1");
        set_pnj_dialogue(project->scene->pnj, "/bed.png", "Bed");
        set_pnj_dialogue(project->scene->pnj, "/skull.png", "Skull1");
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle");
    }
    if (project->player->player_progress_state >= 1) {
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle2");
        add_quest("Aller dans la maison", project->quests, "QUETE1");
    }
    if (project->player->player_progress_state >= 2)
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle3");
    set_all_pnj_dialogues_bis(project);
}
