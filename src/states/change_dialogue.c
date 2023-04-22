/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** changes_dialogue.c
*/

#include "project.h"

void init_dialogues(project_t *project)
{
    set_pnj_dialogue(project->scene->pnj, "/door.png", "Dungeon1");
    set_pnj_dialogue(project->scene->pnj, "/bed.png", "Bed");
    set_pnj_dialogue(project->scene->pnj, "/skull.png", "Skull1");
    set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle");
    set_pnj_dialogue(project->scene->pnj, "/etchebest.png", "Etchebest1");
    set_pnj_dialogue(project->scene->pnj, "/chest.png", "Chest1");
    set_pnj_dialogue(project->scene->pnj, "/chest2.png", "Chest1");
    set_pnj_dialogue(project->scene->pnj, "/mickey.png", "Mickey1");
    set_pnj_dialogue(project->scene->pnj, "/client.png", "Client1");
    set_pnj_dialogue(project->scene->pnj, "/kid.png", "Kid1");
    set_pnj_dialogue(project->scene->pnj, "/door_boss1.png", "DoorBoss1");
    set_pnj_dialogue(project->scene->pnj, "/door_boss2.png", "DoorBoss1");
    set_pnj_dialogue(project->scene->pnj, "/door_boss3.png", "DoorBoss1");
    set_pnj_dialogue(project->scene->pnj, "/heisenberg.png", "Heisenberg1");
    set_pnj_dialogue(project->scene->pnj, "/therock.png", "Therock1");
    set_pnj_dialogue(project->scene->pnj, "/creator.png", "Creator");
    set_pnj_dialogue(project->scene->pnj, "/boat_guy.png", "Boat1");
}

void set_dungeon_dialogues(project_t *project)
{
    if (project->player->player_progress_state >= 7) {
        set_pnj_dialogue(project->scene->pnj, "/chest.png", "Chest2");
        set_pnj_dialogue(project->scene->pnj, "/etchebest.png", "Etchebest2");
        set_pnj_dialogue(project->scene->pnj, "/door_boss1.png", "DoorBoss2");
    }
    if (project->player->player_progress_state >= 9) {
        set_pnj_dialogue(project->scene->pnj, "/chest2.png", "Chest3");
        set_pnj_dialogue(project->scene->pnj, "/heisenberg.png", "Heisenberg2");
        set_pnj_dialogue(project->scene->pnj, "/door_boss2.png", "DoorBoss2");
    }
    if (project->player->player_progress_state >= 11) {
        set_pnj_dialogue(project->scene->pnj, "/therock.png", "Therock2");
        set_pnj_dialogue(project->scene->pnj, "/door_boss3.png", "DoorBoss2");
    }
    if (project->player->player_progress_state >= 12)
        set_pnj_dialogue(project->scene->pnj, "/creator.png", "Creator2");
    if (project->player->player_progress_state >= 13)
        set_pnj_dialogue(project->scene->pnj, "/creator.png", "Creator3");
}

void set_secondary_quest_dialogues(project_t *project)
{
    if (project->player->player_second_state >= 1) {
        set_pnj_dialogue(project->scene->pnj, "/mickey.png", "Mickey2");
        set_pnj_dialogue(project->scene->pnj, "/client.png", "Client2");
    }
    if (project->player->player_second_state >= 2) {
        set_pnj_dialogue(project->scene->pnj, "/client.png", "Client3");
        set_pnj_dialogue(project->scene->pnj, "/kid.png", "Kid2");
    }
    if (project->player->player_second_state >= 3) {
        set_pnj_dialogue(project->scene->pnj, "/kid.png", "Kid3");
        set_pnj_dialogue(project->scene->pnj, "/boat_guy.png", "Boat2");
    }
    if (project->player->player_second_state >= 4) {
        set_pnj_dialogue(project->scene->pnj, "/boat_guy.png", "Boat3");
    }
}

void set_tuto_dialogues(project_t *project)
{
    if (project->player->player_progress_state >= 1) {
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle2");
        add_quest("Aller dans la maison", project->quests, "QUETE1");
    }
    if (project->player->player_progress_state >= 2)
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle3");
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
    init_dialogues(project);
    set_tuto_dialogues(project);
    set_secondary_quest_dialogues(project);
    set_dungeon_dialogues(project);
}
