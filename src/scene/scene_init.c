/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** scene_init.c
*/

#include "project.h"

scene_list_t scenes[2] = {
    {"spawn", (sfVector2f){160, 160}},
    {"plains", (sfVector2f){160, 100}}
};

void next_load_scene(project_t *project, scene_t *scene)
{
    push_back(&scene->images, "background", create_image(0,
    0, my_strcat(scene->name, "/background.png"), (sfIntRect){0,0, 480, 480}),
    IMAGE);
    push_back(&scene->images, "player", create_image(project->player->pos.x,
    project->player->pos.y, "player.png", (sfIntRect){0,0, 16, 16}), IMAGE);
    push_back(&scene->images, "foreground", create_image(0,
    0, my_strcat(scene->name, "/foreground.png"), (sfIntRect){0,0, 480, 480}),
    IMAGE);
    colliders_init(my_strcat(scene->name, "/res.coll"), scene);
}

scene_t *load_scene(project_t *project, int scene_id)
{
    scene_t *scene = malloc(sizeof(scene_t));

    project->scene_id = scene_id;
    if (project->scene != NULL)
        scene_destroy(project->scene);
    scene->camera = sfView_create();
    scene->images = malloc(sizeof(list_t));
    scene->images = NULL;
    scene->colliders = NULL;
    scene->name = scenes[scene_id].name;
    project->player->pos = scenes[scene_id].spawn;
    sfView_setSize(scene->camera, (sfVector2f){256,144});
    sfView_setCenter(scene->camera, project->player->pos);
    sfRenderWindow_setView(project->window, scene->camera);
    next_load_scene(project, scene);
    return scene;
}
