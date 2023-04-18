/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu_draw.c
*/

#include "project.h"

void draw_main_menu(project_t *project)
{
    image_t *background = project->main_menu->background;

    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(project->window,
    background->sprite, NULL);
    update_button(project->main_menu->play, project, project->event);
    update_button(project->main_menu->settings, project, project->event);
    update_button(project->main_menu->quit, project, project->event);
    if (project->main_menu->state == PLAY) {
        update_button(project->main_menu->new_game, project, project->event);
        if (project->main_menu->save != NULL)
            update_button(project->main_menu->load_game, project, project->event);
    }
}

void draw_pause_menu(project_t *project)
{
    image_t *background = project->pause_menu->background;

    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(project->window,
    background->sprite, NULL);
    update_button(project->pause_menu->resume, project, project->event);
    update_button(project->pause_menu->save, project, project->event);
    update_button(project->pause_menu->settings, project, project->event);
    update_button(project->pause_menu->back_menu, project, project->event);
}
