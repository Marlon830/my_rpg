/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** main.c
*/

#include "../include/project.h"

void update(project_t *project)
{
    int movement_x = 0, movement_y = 0;
    bool moved = false;
    
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        movement_y -= project->player_speed;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        movement_y += project->player_speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        movement_x -= project->player_speed;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        movement_x += project->player_speed;
    moved = movement_x != 0 || movement_y != 0;
    if (moved) {
        project->dt = sfClock_getElapsedTime(project->clock).microseconds;
        project->movement.x = movement_x / project->dt;
        project->movement.y = movement_y / project->dt;
        move_camera(project->graphic, project);
    }

}

void main_loop(project_t *project)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
        graphic_event(project);
        update(project);
        graphic_draw(project->graphic);
        sfClock_restart(project->clock);
    }
    graphic_destroy(project->graphic);
    free(project);
}

project_t *init_project(void)
{
    project_t *project = malloc(sizeof(project_t));

    project->graphic = graphic_init();
    project->player_speed = 500;
    project->pressed = malloc(sizeof(keys_t));
    project->pressed->d = false;
    project->pressed->s = false;
    project->pressed->z = false;
    project->pressed->q = false;
    project->clock = sfClock_create();
    project->movement = (sfVector2f){0, 0};
    return project;
}

int main(void)
{
    project_t *project = init_project();
    main_loop(project);
    return 0;
}
