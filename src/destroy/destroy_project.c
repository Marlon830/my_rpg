/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_project.c
*/

#include "project.h"

void destroy_project(project_t *project)
{
    destroy_inventory(project->inventory);
    sfClock_destroy(project->clock);
    destroy_dialogue(project->actual_dial);
    destroy_player_game(project->player);
    destroy_main_menu(project->main_menu);
    destroy_pause_menu(project->pause_menu);
    destroy_quest(project->quests);
    if (project->quests_button != NULL)
        sfText_destroy(project->quests_button);
    destroy_credit(project->credit);
}
