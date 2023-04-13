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
    update_button(project->main_menu->quit, project, project->event);
    sfRenderWindow_display(project->window);
}
