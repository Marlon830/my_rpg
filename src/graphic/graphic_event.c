/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** graphic_event.c
*/

#include "../../include/project.h"

void event_scene_one(project_t *project, graphic_t *scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(project->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(project->window);
    }
}

void event_all_scenes(project_t *project)
{
    switch (project->scene_id) {
        case 1: event_scene_one(project, project->scene_one); break;
        default: break;
    }
}
