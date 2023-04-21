/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** changes_dialogue.c
*/

#include "project.h"

void change_state_with_dialogue(project_t *project, all_pnjs_t *act_pnj)
{
    theoronfle_quest(project, act_pnj);
    bed_quest(project, act_pnj);
    skull_quest(project, act_pnj);
    door_quest(project, act_pnj);
    chest_quest(project, act_pnj);
    enemy1_quest(project, act_pnj);
    mickey_quest(project, act_pnj);
    client_quest(project, act_pnj);
    dungeon_door1_quest(project, act_pnj);
}

void change_state_with_scene(project_t *project, int to_scene_id)
{
    if (project->player->player_progress_state == 0 && to_scene_id == HOUSE)
        project->player->player_progress_state = 3;
    if (project->player->player_progress_state == 1 && to_scene_id == HOUSE)
        project->player->player_progress_state = 2;
}

void set_all_pnj_dialogues_ter(project_t *project)
{
    if (project->player->player_second_state >= 2) {
        set_pnj_dialogue(project->scene->pnj, "/client.png", "Client3");
    }
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
    if (project->player->player_progress_state >= 7) {
        set_pnj_dialogue(project->scene->pnj, "/chest.png", "Chest2");
        set_pnj_dialogue(project->scene->pnj, "/enemy.png", "Enemy2");
        set_pnj_dialogue(project->scene->pnj, "/door_boss1.png", "DoorBoss2");
    }
    if (project->player->player_second_state >= 1) {
        set_pnj_dialogue(project->scene->pnj, "/mickey.png", "Mickey2");
        set_pnj_dialogue(project->scene->pnj, "/client.png", "Client2");
    }
    set_all_pnj_dialogues_ter(project);
}

void set_all_pnj_dialogues(project_t *project)
{
    if (project->player->player_progress_state >= 0) {
        set_pnj_dialogue(project->scene->pnj, "/door.png", "Dungeon1");
        set_pnj_dialogue(project->scene->pnj, "/bed.png", "Bed");
        set_pnj_dialogue(project->scene->pnj, "/skull.png", "Skull1");
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle");
        set_pnj_dialogue(project->scene->pnj, "/enemy.png", "Enemy1");
        set_pnj_dialogue(project->scene->pnj, "/chest.png", "Chest1");
        set_pnj_dialogue(project->scene->pnj, "/mickey.png", "Mickey1");
        set_pnj_dialogue(project->scene->pnj, "/client.png", "Client1");
        set_pnj_dialogue(project->scene->pnj, "/door_boss1.png", "DoorBoss1");
    }
    if (project->player->player_progress_state >= 1) {
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle2");
        add_quest("Aller dans la maison", project->quests, "QUETE1");
    }
    if (project->player->player_progress_state >= 2)
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle3");
    set_all_pnj_dialogues_bis(project);
}
