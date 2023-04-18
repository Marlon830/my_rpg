/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_clicked.c
*/

#include "project.h"


void play_button(project_t *project)
{
    project->status = GAME;
    project->scene = load_scene(project, 0);
}

void display_play(project_t *project)
{
    project->main_menu->state = PLAY;
}

void display_settings(project_t *project)
{
    project->main_menu->state = SETTINGS;
}

void quit_button(project_t *project)
{
    sfRenderWindow_close(project->window);
}
