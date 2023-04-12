/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** main.c
*/

#include "project.h"
#include "utils.h"

void main_loop(project_t *project)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
        scene_event(project);
        update_scene(project);
        sfRenderWindow_display(project->window);
    }
    scene_destroy(project->scene);
    sfRenderWindow_destroy(project->window);
    free(project);
}

player_t *init_player(int x, int y)
{
    player_t *player = malloc(sizeof(player_t));

    player->col = malloc(sizeof(sfFloatRect));
    player->pos.x = x;
    player->pos.y = y;
    player->col->left = player->pos.x;
    player->col->top = player->pos.y;
    player->col->width = 16;
    player->col->height = 8;
    player->speed = 1;
    player->move = (sfVector2f) {0, 0};
    player->state = IDLE_DOWN;
    return player;
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
    project->player = init_player(160, 160);
    project->scene = load_scene(project, 0);
    return project;
}

int main(void)
{
    project_t *project = init_project();

    main_loop(project);
    return 0;
}
