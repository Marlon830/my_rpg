/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_scene.c
*/

#include "project.h"

void update_scene(project_t *project)
{
    float movement_x = 0, movement_y = 0;
    bool moved = false;

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        movement_y -= project->player->speed;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        movement_y += project->player->speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        movement_x -= project->player->speed;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        movement_x += project->player->speed;
    moved = movement_x != 0 || movement_y != 0;
    if (moved) {
        project->dt = sfTime_asSeconds(sfClock_getElapsedTime(project->clock));
        project->player->move.x = movement_x * project->dt;
        project->player->move.y = movement_y * project->dt;
        move_camera(project, project->scene);
    }
    scene_draw(project, project->scene);
}
