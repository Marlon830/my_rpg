/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** scene_init.c
*/

#include "project.h"

spawn_t island_tp[] = {{(sfFloatRect){256, 144, 16, 16}, 1,
(sfVector2f){176, 60}}};
spawn_t house_tp[] = {{(sfFloatRect){176, 48, 16, 16}, 0,
(sfVector2f){240, 160}}, {(sfFloatRect){192, 48, 16, 16}, 0,
(sfVector2f){240, 160}},
{(sfFloatRect){224, 224, 16, 16}, 2, (sfVector2f){272, 224}}};
spawn_t sus_tp[] = {{(sfFloatRect){288, 240, 16, 16}, 1,
(sfVector2f){208, 208}}, {(sfFloatRect){304, 240, 16, 16}, 1,
(sfVector2f){208, 208}}};

scene_list_t scenes[4] = {
    {"island", island_tp, 1, (sfVector2f){480, 480}},
    {"house", house_tp, 3, (sfVector2f){256, 256}},
    {"sus", sus_tp, 2, (sfVector2f){880, 432}}
};

void next_load_scene(project_t *project, scene_t *scene, sfVector2f size)
{
    image_t *background = create_image((sfVector2f){16, 16},
    my_strcat(scene->name, "/background.png"),
    (sfIntRect){0, 0, 480, 480}, size);
    background->nb_sprite = 1;
    image_t *player = create_image((sfVector2f){project->player->pos.x,
    project->player->pos.y}, "/player.png", (sfIntRect){0, 0, 64, 128},
    (sfVector2f){16, 16});
    player->nb_sprite = 4;
    image_t *foreground = create_image((sfVector2f){16, 16},
    my_strcat(scene->name, "/foreground.png"),
    (sfIntRect){0, 0, 480, 480}, size);
    foreground->nb_sprite = 1;

    push_back(&scene->images, "background", background, IMAGE);
    push_back(&scene->images, "player", player, IMAGE);
    push_back(&scene->images, "foreground", foreground, IMAGE);
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
    scene->tp = scenes[scene_id].tp;
    scene->nb_tp = scenes[scene_id].nb_tp;
    sfView_setSize(scene->camera, (sfVector2f){256, 144});
    sfView_setCenter(scene->camera, project->player->pos);
    sfRenderWindow_setView(project->window, scene->camera);
    next_load_scene(project, scene, scenes[scene_id].size);
    return scene;
}
