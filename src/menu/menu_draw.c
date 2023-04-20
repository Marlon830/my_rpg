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

void draw_main_menu(project_t *project)
{
    image_t *background = project->main_menu->background;

    sfText_setString(project->main_menu->act_volume,
    int_to_str((int) project->volume));
    sfMusic_setVolume(project->main_menu->music, project->volume);
    sfMusic_setVolume(project->main_menu->music_ingame, project->volume);
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(project->window,
    background->sprite, NULL);
    update_button(project->main_menu->play, project);
    update_button(project->main_menu->settings, project);
    update_button(project->main_menu->quit, project);
    if (project->main_menu->state == PLAY)
        update_button(project->main_menu->new_game, project);
    if (project->main_menu->state == PLAY &&
    project->main_menu->save != NULL)
        update_button(project->main_menu->load_game, project);
    if (project->main_menu->state == SETTINGS) {
        update_settings(project);
    }
}

void draw_pause_menu(project_t *project)
{
    image_t *background = project->pause_menu->background;

    sfText_setString(project->pause_menu->act_volume,
    int_to_str((int) project->volume));
    sfMusic_setVolume(project->main_menu->music_ingame, project->volume);
    sfMusic_setVolume(project->main_menu->music, project->volume);
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(project->window,
    background->sprite, NULL);
    update_button(project->pause_menu->resume, project);
    update_button(project->pause_menu->save, project);
    update_button(project->pause_menu->settings, project);
    update_button(project->pause_menu->back_menu, project);
    if (project->pause_menu->state == SETTINGS) {
        update_settings_pause(project);
    }
}
