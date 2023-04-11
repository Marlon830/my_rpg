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
        update_all_scenes(project);
        sfClock_restart(project->clock);
    }
    graphic_destroy(project->scene_one);
    sfRenderWindow_destroy(project->window);
    free(project);
}

project_t *init_project(void)
{
    project_t *project = malloc(sizeof(project_t));
    sfVideoMode mode = (sfVideoMode){1920, 1080, 32};

    project->window = sfRenderWindow_create(mode, "Quoi ? Feur",
    sfClose | sfFullscreen, NULL);
    project->scene_one = graphic_init(project, "spawn.png", "assets/res.coll", "player.png");
    project->scene_two = graphic_init(project, "spawn.png", "assets/res.coll", "player.png");
    project->clock = sfClock_create();
    project->scene_id = 1;
    return project;
}

int main(void)
{
    project_t *project = init_project();

    main_loop(project);
    return 0;
}
