/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_scene_one.c
*/

#include "project.h"

void update_scene_one(project_t *project, graphic_t *scene)
{
    int movement_x = 0, movement_y = 0;
    bool moved = false;

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        movement_y -= scene->player_speed;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        movement_y += scene->player_speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        movement_x -= scene->player_speed;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        movement_x += scene->player_speed;
    moved = movement_x != 0 || movement_y != 0;
    if (moved) {
        project->dt = sfClock_getElapsedTime(project->clock).microseconds;
        scene->movement.x = movement_x / project->dt;
        scene->movement.y = movement_y / project->dt;
        move_camera(project, scene);
    }
    graphic_draw(project, scene);
}

void update_scene_two(project_t *project, graphic_t *scene)
{
    int movement_x = 0, movement_y = 0;
    bool moved = false;

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        movement_y -= scene->player_speed;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        movement_y += scene->player_speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        movement_x -= scene->player_speed;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        movement_x += scene->player_speed;
    moved = movement_x != 0 || movement_y != 0;
    if (moved) {
        project->dt = sfClock_getElapsedTime(project->clock).microseconds;
        scene->movement.x = movement_x / project->dt;
        scene->movement.y = movement_y / project->dt;
        move_camera(project, scene);
    }
    graphic_draw(project, scene);
}
