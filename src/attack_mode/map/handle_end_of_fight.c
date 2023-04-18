/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handle_end_of_fight.c
*/

#include "attack_mode.h"
#include "project.h"

void handle_end_of_fight(project_t *project, int scene_to_load)
{
    if (project->battle_scene->win) {
            destroy_battle_scene(project->battle_scene);
            project->battle_scene = create_standard_battle_scene();
            project->status = GAME;
            project->scene = load_scene(project, project->scene_id);
        }
}
