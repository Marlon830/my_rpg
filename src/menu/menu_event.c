/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu_event.c
*/

#include "project.h"

int can_slider_move(sfFloatRect rect, sfEvent event)
{
    if (event.mouseMove.x >= rect.left &&
    event.mouseMove.x <= (rect.width + rect.left))
        return 1;
    return 0;
}

void slider_event(project_t *project, sfEvent event)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds
    (project->main_menu->slider->rect);
    float rad = sfCircleShape_getRadius(project->main_menu->slider->circle);
    float cir_pos_in_rect = 0;

    rect = (sfFloatRect) {rect.left, rect.top - rad / 2,
    rect.width, rad * 2};
    if (event.type == sfEvtMouseButtonPressed &&
    sfFloatRect_contains(&rect, event.mouseButton.x, event.mouseButton.y))
        project->main_menu->is_sliding = 1;
    if (event.type == sfEvtMouseButtonReleased)
        project->main_menu->is_sliding = 0;
    if (event.type == sfEvtMouseMoved && project->main_menu->is_sliding == 1
    && can_slider_move(rect, event)) {
        project->main_menu->slider->position_circle.x = event.mouseMove.x - rad;
        cir_pos_in_rect = project->main_menu->slider->position_circle.x
        - project->main_menu->slider->position.x;
        project->main_menu->slider->value = (cir_pos_in_rect / 289) * 100;
    }
}

void button_click(button_t *button, project_t *project, sfEvent event)
{
    if (button->is_clicked(button, &event.mouseButton))
        button->clicked(project);
}

void main_menu_button_event(project_t *project)
{
    main_menu_t *main = project->main_menu;

    button_click(main->play, project, project->event);
    button_click(main->settings, project, project->event);
    button_click(main->quit, project, project->event);
    if (main->state == PLAY) {
        button_click(main->load_game, project, project->event);
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
        if (project->event.type == sfEvtClosed)
            sfRenderWindow_close(project->window);
        if (project->event.type == sfEvtKeyPressed &&
        project->event.key.code == sfKeyEscape)
            sfRenderWindow_close(project->window);
        if (project->event.type == sfEvtMouseButtonPressed)
            main_menu_button_event(project);
    }
}

void pause_menu_event(project_t *project)
{
    while (sfRenderWindow_pollEvent(project->window, &project->event)) {
        if (project->event.type == sfEvtClosed)
            sfRenderWindow_close(project->window);
        if (project->event.type == sfEvtKeyPressed &&
        project->event.key.code == sfKeyEscape)
            project->status = GAME;
        if (project->event.type == sfEvtMouseButtonPressed) {
            pause_menu_button_event(project);
        }
        slider_event(project, project->event);
    }
}
