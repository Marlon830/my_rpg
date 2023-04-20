/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** events_battle_scene.c
*/

#include "attack_mode.h"
#include "project.h"
#include "utils.h"

void battle_scene_event(project_t *project)
{
    sfRenderWindow_setView(project->window,
            project->battle_scene->view);
    while (sfRenderWindow_pollEvent(project->window, &project->event)) {
        analyse_events(project->window, project->event,
    project->battle_scene, project->battle_scene->hand);
    }
}
