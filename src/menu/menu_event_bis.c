/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu_event_bis.c
*/

#include "project.h"

void main_menu_button_event(project_t *project)
{
    main_menu_t *main = project->main_menu;

    button_click(main->play, project, project->event);
    button_click(main->settings, project, project->event);
    button_click(main->quit, project, project->event);
    if (main->state == PLAY) {
        if (main->save != NULL) {
            button_click(main->load_game, project, project->event);
        }
        button_click(main->new_game, project, project->event);
    }
}

void pause_menu_button_event(project_t *project)
{
    pause_menu_t *pause = project->pause_menu;

    button_click(pause->resume, project, project->event);
    button_click(pause->save, project, project->event);
    button_click(pause->settings, project, project->event);
    button_click(pause->back_menu, project, project->event);
}

void main_menu_event(project_t *project)
{
    while (sfRenderWindow_pollEvent(project->window, &project->event)) {
        if (project->event.type == sfEvtClosed) {
            sfRenderWindow_close(project->window);
        }
        if (project->event.type == sfEvtMouseButtonPressed)
            main_menu_button_event(project);
        slider_event(project, project->event);
    }
}

void pause_menu_event(project_t *project)
{
    while (sfRenderWindow_pollEvent(project->window, &project->event)) {
        if (project->event.type == sfEvtClosed) {
            sfRenderWindow_close(project->window);
        }
        if (project->event.type == sfEvtKeyPressed &&
        project->event.key.code == sfKeyEscape)
            project->status = GAME;
        if (project->event.type == sfEvtMouseButtonPressed) {
            pause_menu_button_event(project);
        }
        slider_event_pause(project, project->event);
    }
}
