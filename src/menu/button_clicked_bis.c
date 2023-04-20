/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_clicked_bis.c
*/

#include "project.h"

void back_menu_button(project_t *project)
{
    sfMusic_stop(project->main_menu->music_ingame);
    project->status = MAIN_MENU;
    project->main_menu->save = get_save(project);
    sfMusic_play(project->main_menu->music);
}

void resume_button(project_t *project)
{
    project->status = GAME;
}
