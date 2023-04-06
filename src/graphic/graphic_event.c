/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** graphic_event.c
*/

#include "../../include/project.h"

void graphic_key_event(project_t *project, sfKeyCode key)
{
    switch (key) {
        case sfKeyEscape : sfRenderWindow_close(WINDOW); break;
        case sfKeyZ : move_camera(project->graphic,
        (sfVector2f){0,  -project->player_speed}, key); break;
        case sfKeyS : move_camera(project->graphic,
        (sfVector2f){0, project->player_speed}, key); break;
        case sfKeyQ : move_camera(project->graphic,
        (sfVector2f){-project->player_speed, 0}, key); break;
        case sfKeyD : move_camera(project->graphic,
        (sfVector2f){project->player_speed, 0}, key); break;
    }
}

void graphic_event(project_t *project)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(WINDOW, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        if (event.type == sfEvtKeyPressed)
            graphic_key_event(project, event.key.code);
    }
}
