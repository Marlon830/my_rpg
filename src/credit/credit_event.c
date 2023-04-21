/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_event.c
*/

#include "project.h"

void credit_event(project_t *project)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(project->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(project->window);
    }
}
