/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** chest_dialogue_state.c
*/

#include "project.h"

void chest_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/chest.png")) {
        if (project->player->player_progress_state == 7) {
            add_elem(project->inventory->bag, "assets/object/pants_gold.png",
            PANTS, 1);
            project->player->player_progress_state = 8;
        }
    }
}

void chest2_quest(project_t *project, all_pnjs_t *act_pnj)
{
    if (!my_strcmp(act_pnj->name, "/chest2.png")) {
        if (project->player->player_progress_state == 9) {
            add_elem(project->inventory->bag, "assets/object/boots_gold.png",
            BOOTS, 1);
            project->player->player_progress_state = 10;
        }
    }
}
