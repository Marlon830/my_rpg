/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** updates_scenes.c
*/

#include "project.h"

void update_all_scenes(project_t *project)
{
    event_all_scenes(project);
    sfRenderWindow_clear(project->window, sfBlack);
    switch (project->scene_id) {
        case 1: update_scene_one(project, project->scene_one); break;
        default: break;
    }
    update_inventory(project);
    sfRenderWindow_display(project->window);
}
