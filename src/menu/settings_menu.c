/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** settings_menu.c
*/

#include "project.h"

void update_button_settings(project_t *project)
{
    button_click(project->main_menu->fullscreen, project, project->event);
    button_click(project->main_menu->windowed, project,
    project->event);
    button_click(project->main_menu->first_resolution,
    project, project->event);
    button_click(project->main_menu->second_resolution,
    project, project->event);
    update_button(project->main_menu->fullscreen, project);
    update_button(project->main_menu->windowed, project);
    update_button(project->main_menu->first_resolution,
    project);
    update_button(project->main_menu->second_resolution,
    project);
}

void update_button_settings_pause(project_t *project)
{
    button_click(project->pause_menu->fullscreen, project, project->event);
    button_click(project->pause_menu->windowed, project,
    project->event);
    button_click(project->pause_menu->first_resolution,
    project, project->event);
    button_click(project->pause_menu->second_resolution,
    project, project->event);
    update_button(project->pause_menu->fullscreen, project);
    update_button(project->pause_menu->windowed, project);
    update_button(project->pause_menu->first_resolution,
    project);
    update_button(project->pause_menu->second_resolution,
    project);
}

void update_settings(project_t *project)
{
    update_button_settings(project);
    sfRenderWindow_drawText(WINDOW, project->main_menu->act_volume, NULL);
    update_slider(project, project->main_menu->slider);
    sfRenderWindow_drawRectangleShape(WINDOW,
    project->main_menu->slider->rect, NULL);
    sfRenderWindow_drawCircleShape(WINDOW,
    project->main_menu->slider->circle, NULL);
}

void update_settings_pause(project_t *project)
{
    update_button_settings_pause(project);
    sfRenderWindow_drawText(WINDOW, project->pause_menu->act_volume, NULL);
    update_slider(project, project->pause_menu->slider);
    sfRenderWindow_drawRectangleShape(WINDOW,
    project->pause_menu->slider->rect, NULL);
    sfRenderWindow_drawCircleShape(WINDOW,
    project->pause_menu->slider->circle, NULL);
}
