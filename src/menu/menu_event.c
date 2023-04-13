/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu_event.c
*/

#include "project.h"


void menu_event(project_t *project)
{
    while (sfRenderWindow_pollEvent(project->window, &project->event)) {
        if (project->event.type == sfEvtClosed)
            sfRenderWindow_close(project->window);
        if (project->event.type == sfEvtKeyPressed &&
        project->event.key.code == sfKeyEscape)
            sfRenderWindow_close(project->window);
        if (project->event.type == sfEvtKeyPressed &&
        project->event.key.code == sfKeyEnter) {
            project->status = GAME;
            project->scene = load_scene(project, 0);
        }
    }
}
