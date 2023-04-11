/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** main.c
*/

#include "../include/project.h"

void main_loop(project_t *project)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
        scene_event(project);
        update_scene(project);
        sfRenderWindow_display(project->window);
        sfClock_restart(project->clock);
    }
    scene_destroy(project->scene);
    sfRenderWindow_destroy(project->window);
    free(project);
}

project_t *init_project(void)
{
    project_t *project = malloc(sizeof(project_t));
    sfVideoMode mode = (sfVideoMode){1920, 1080, 32};

    project->window = sfRenderWindow_create(mode, "Quoi ? Feur",
    sfClose | sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(project->window, 60);
    sfRenderWindow_setKeyRepeatEnabled(project->window, sfFalse);
    project->clock = sfClock_create();
    project->player = malloc(sizeof(player_t));
    project->player->col = malloc(sizeof(sfFloatRect));
    project->player->col->left = project->player->pos.x;
    project->player->col->top = project->player->pos.y;
    project->player->col->width = 16;
    project->player->col->height = 8;
    project->player->speed = 5000;
    project->player->move = (sfVector2f) {0, 0};
    project->scene = load_scene(project, 0);
    return project;
}

int main(void)
{
    project_t *project = init_project();
    main_loop(project);
    return 0;
}
