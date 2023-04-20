/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** scene_init.c
*/

#include "project.h"

all_pnjs_t *create_pnj(char *dial,
    sfFloatRect *pos_size, char *id)
{
    all_pnjs_t *pnj = malloc(sizeof(*pnj));
    sfFloatRect *rect = malloc(sizeof(sfFloatRect));

    rect->left = pos_size->left - 32;
    rect->top = pos_size->top - 32;
    rect->width = 64;
    rect->height = 64;
    pnj->dial = dial;
    pnj->hitbox = rect;
    pnj->pos_size = pos_size;
    pnj->sprite = NULL;
    pnj->can_talk = 0;
    pnj->name = id;
    return pnj;
}

void load_pnj(scene_t *scene)
{
    list_t *tmp = scene->pnj;
    all_pnjs_t *pnj;

    while (tmp != NULL) {
        pnj = tmp->element;
        pnj->sprite = create_image(
            (sfVector2f){pnj->pos_size->left, pnj->pos_size->top},
            my_strcat(scene->name, pnj->name),
            (sfIntRect){0, 0, pnj->pos_size->width, pnj->pos_size->height},
            (sfVector2f){16, 16}
        );
        pnj->sprite->nb_sprite = 4;
        push_back(&scene->images, pnj->name, pnj->sprite, IMAGE);
        tmp = tmp->next;
    }
}

void next_load_scene(project_t *project, scene_t *scene, sfVector2f size)
{
    image_t *background = create_image((sfVector2f){0, 0},
    my_strcat(scene->name, "/background.png"),
    (sfIntRect){0, 0, size.x, size.y}, size);
    background->nb_sprite = 1;
    image_t *player = create_image((sfVector2f){project->player->pos.x,
    project->player->pos.y}, "/player.png", (sfIntRect){0, 0, 128, 256},
    (sfVector2f){32, 32});
    player->nb_sprite = 4;
    image_t *foreground = create_image((sfVector2f){0, 0},
    my_strcat(scene->name, "/foreground.png"),
    (sfIntRect){0, 0, size.x, size.y}, size);
    foreground->nb_sprite = 1;
    push_back(&scene->images, "background", background, IMAGE);
    load_pnj(scene);
    push_back(&scene->images, "player", player, IMAGE);
    project->player->character = get_item(scene->images, "player");
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
    scene->pnj = map->pnj;
    scene->map_size = map->size;
    change_view(project, scene->camera, (sfVector2f){256, 144},
    project->player->pos);
    next_load_scene(project, scene, map->size);
    return scene;
}
