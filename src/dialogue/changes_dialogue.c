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
        }
    }
}

void change_state_with_dialogue(project_t *project, all_pnjs_t *act_pnj)
{
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
    if (project->player->player_progress_state == 0 &&
    !my_strcmp(act_pnj->name, "/theodore.png"))
        project->player->player_progress_state = 1;
    if (!my_strcmp(act_pnj->name, "/bed.png")) {
        project->status = FIGHT;
        project->battle_scene = create_battle_scene_from_file(
    "assets/fight_scene/bed_map.txt",
    "assets/fight_scene/bed_enemies.txt");
    }
}

void change_state_with_scene(project_t *project, int to_scene_id)
{
    if (project->player->player_progress_state == 0 && to_scene_id == HOUSE)
        project->player->player_progress_state = 3;
    if (project->player->player_progress_state == 1 && to_scene_id == HOUSE)
        project->player->player_progress_state = 2;
}

void set_all_pnj_dialogues(project_t *project)
{
    set_pnj_dialogue(project->scene->pnj, "/door.png", "Dungeon1");
    set_pnj_dialogue(project->scene->pnj, "/bed.png", "Bed");
    set_pnj_dialogue(project->scene->pnj, "/skull.png", "Skull1");
    if (project->player->player_progress_state == 0)
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle");
    if (project->player->player_progress_state == 1) {
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle2");
        add_quest("Aller dans la maison", project->quests, "QUETE1");
    }
    if (project->player->player_progress_state == 2)
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle3");
    if (project->player->player_progress_state == 3)
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle4");
    if (project->player->player_progress_state == 4) {
        set_pnj_dialogue(project->scene->pnj, "/skull.png", "Skull2");
        set_pnj_dialogue(project->scene->pnj, "/theodore.png", "Theoronfle5");
    }
}
