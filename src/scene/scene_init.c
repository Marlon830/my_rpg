/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** scene_init.c
*/

#include "project.h"

void next_load_scene(project_t *project, scene_t *scene, sfVector2f size)
{
    image_t *background = create_image((sfVector2f){0, 0},
    my_strcat(scene->name, "/background.png"),
    (sfIntRect){0, 0, 480, 480}, size);
    background->nb_sprite = 1;
    image_t *player = create_image((sfVector2f){project->player->pos.x,
    project->player->pos.y}, "/player.png", (sfIntRect){0, 0, 64, 128},
    (sfVector2f){16, 16});
    player->nb_sprite = 4;
    image_t *foreground = create_image((sfVector2f){0, 0},
    my_strcat(scene->name, "/foreground.png"),
    (sfIntRect){0, 0, 480, 480}, size);
    foreground->nb_sprite = 1;

    push_back(&scene->images, "background", background, IMAGE);
    push_back(&scene->images, "player", player, IMAGE);
    push_back(&scene->images, "foreground", foreground, IMAGE);
    colliders_init(my_strcat(scene->name, "/res.coll"), scene);
}

void change_view(project_t *project, sfView *camera,
sfVector2f size, sfVector2f pos)
{
    sfView_setSize(camera, size);
    sfView_setCenter(camera, pos);
    sfRenderWindow_setView(project->window, camera);
}

scene_t *load_scene(project_t *project, int scene_id)
{
    scene_t *scene = malloc(sizeof(scene_t));
    list_t *tmp = project->scenes;
    for (int i = 0; i != scene_id; i++) tmp = tmp->next;
    map_t *map = tmp->element;

    project->scene_id = scene_id;
    if (project->scene != NULL)
        scene_destroy(project->scene);
    scene->camera = sfView_create();
    scene->images = malloc(sizeof(list_t));
    scene->images = NULL;
    scene->colliders = NULL;
    scene->name = map->name;
    scene->tp = map->tp;
    scene->nb_tp = map->nb_tp;
    change_view(project, scene->camera, (sfVector2f){256, 144},
    project->player->pos);
    next_load_scene(project, scene, map->size);
    return scene;
}
