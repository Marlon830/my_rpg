/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_clicked_ter.c
*/

#include "project.h"

void set_win_fullscreen(project_t *project)
{
    sfRenderWindow_close(project->window);
    project->window = sfRenderWindow_create(project->mode,
    "Le Quoi ? Feur et la quete du crampter", sfClose | sfFullscreen, NULL);
    project->is_fullscreen = 1;
    sfRenderWindow_setFramerateLimit(project->window, 60);
    sfRenderWindow_setKeyRepeatEnabled(project->window, sfFalse);
}

void set_win_windowed(project_t *project)
{
    sfRenderWindow_close(project->window);
    project->window = sfRenderWindow_create(project->mode,
    "Le Quoi ? Feur et la quete du crampter", sfClose, NULL);
    project->is_fullscreen = 0;
    sfRenderWindow_setFramerateLimit(project->window, 60);
    sfRenderWindow_setKeyRepeatEnabled(project->window, sfFalse);
}

void set_first_resolution(project_t *project)
{
    sfView *view = sfView_create();

    sfRenderWindow_close(project->window);
    project->mode = (sfVideoMode) {1920, 1080, 32};
    if (project->is_fullscreen == 1)
        project->window = sfRenderWindow_create(project->mode,
        "Le Quoi ? Feur et la quete du crampter", sfClose | sfFullscreen, NULL);
    else
        project->window = sfRenderWindow_create(project->mode,
        "Le Quoi ? Feur et la quete du crampter", sfClose, NULL);
    sfRenderWindow_setSize(WINDOW, (sfVector2u) {1920, 1080});
    sfView_reset(view, (sfFloatRect) {0, 0, 1920, 1080});
    sfRenderWindow_setView(WINDOW, view);
    sfRenderWindow_setFramerateLimit(project->window, 60);
    sfRenderWindow_setKeyRepeatEnabled(project->window, sfFalse);
}

void set_second_resolution(project_t *project)
{
    sfView *view = sfView_create();

    sfRenderWindow_close(project->window);
    project->mode = (sfVideoMode) {1920, 1080, 32};
    if (project->is_fullscreen == 1)
        project->window = sfRenderWindow_create(project->mode,
        "Le Quoi ? Feur et la quete du crampter", sfClose | sfFullscreen, NULL);
    else
        project->window = sfRenderWindow_create(project->mode,
        "Le Quoi ? Feur et la quete du crampter", sfClose, NULL);
    sfRenderWindow_setSize(WINDOW, (sfVector2u) {1280, 720});
    sfView_reset(view, (sfFloatRect) {0, 0, 1920, 1080});
    sfRenderWindow_setView(WINDOW, view);
    sfRenderWindow_setFramerateLimit(project->window, 60);
    sfRenderWindow_setKeyRepeatEnabled(project->window, sfFalse);
}

void display_settings_pause(project_t *project)
{
    project->pause_menu->state = SETTINGS;
}
