/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu_draw.c
*/

#include "project.h"

void update_slider(project_t *project, slider_t *slider)
{
    int ans = slider->value;

    sfCircleShape_setPosition(slider->circle, slider->position_circle);
    project->volume = ans > 0 ? ans : 0;
}

void update_settings(project_t *project)
{
    update_button(project->main_menu->fullscreen, project,
    project->event);
    update_button(project->main_menu->windowed, project,
    project->event);
    update_button(project->main_menu->first_resolution,
    project, project->event);
    update_button(project->main_menu->second_resolution,
    project, project->event);
    sfRenderWindow_drawText(WINDOW, project->main_menu->act_volume, NULL);
    update_slider(project, project->main_menu->slider);
    sfRenderWindow_drawRectangleShape(WINDOW,
    project->main_menu->slider->rect, NULL);
    sfRenderWindow_drawCircleShape(WINDOW,
    project->main_menu->slider->circle, NULL);
}

void draw_main_menu(project_t *project)
{
    image_t *background = project->main_menu->background;

    sfText_setString(project->main_menu->act_volume,
    int_to_str((int) project->volume));
    sfMusic_setVolume(project->main_menu->music, project->volume);
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(project->window,
    background->sprite, NULL);
    update_button(project->main_menu->play, project, project->event);
    update_button(project->main_menu->settings, project, project->event);
    update_button(project->main_menu->quit, project, project->event);
    if (project->main_menu->state == PLAY) {
        update_button(project->main_menu->new_game, project, project->event);
        update_button(project->main_menu->load_game, project, project->event);
    }
    if (project->main_menu->state == SETTINGS) {
        update_settings(project);
    }
}
