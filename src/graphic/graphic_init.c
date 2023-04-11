/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** graphic_init.c
*/

#include "project.h"

void next_graphic_init(project_t *project, graphic_t *scene)
{
    scene->player_col->width = 16;
    scene->player_col->height = 8;
    sfView_setSize(scene->camera, (sfVector2f){256,144});
    sfView_setCenter(scene->camera, scene->player_pos);
    sfRenderWindow_setView(project->window, scene->camera);
    push_back(&scene->images, "map", create_image(0,
    0, "spawn.png", (sfIntRect){0,0, 480, 480}), IMAGE);
    push_back(&scene->images, "player", create_image(scene->player_pos.x,
    scene->player_pos.y, "player.png", (sfIntRect){0,0, 16, 16}), IMAGE);
    colliders_init("./assets/res.coll", scene);
    scene->player_speed = 2000;
    scene->movement = (sfVector2f) {0, 0};
}

graphic_t *graphic_init(project_t *project)
{
    graphic_t *scene = malloc(sizeof(graphic_t));
    sfVideoMode mode = (sfVideoMode){1920, 1080, 32};

    project->window = sfRenderWindow_create(mode, "Quoi ? Feur",
    sfClose | sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(project->window, 60);
    sfRenderWindow_setKeyRepeatEnabled(project->window, sfFalse);
    scene->camera = sfView_create();
    scene->player_pos = (sfVector2f){160, 160};
    scene->images = malloc(sizeof(list_t));
    scene->images = NULL;
    scene->colliders = NULL;
    scene->player_col = malloc(sizeof(sfFloatRect));
    scene->player_col->left = scene->player_pos.x;
    scene->player_col->top = scene->player_pos.y + 8;
    next_graphic_init(project, scene);
    return scene;
}
