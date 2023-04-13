/*
** EPITECH PROJECT, 2022
** tiled-to-c
** File description:
** scene_create.c
*/

#include "scene.h"
#include "utils.h"
#include "project.h"
#include <string.h>

image_t *create_image(sfVector2f pos, char *path, sfIntRect rect,
sfVector2f size)
{
    image_t *image = malloc(sizeof(image_t));

    image->pos = pos;
    image->texture = sfTexture_createFromFile(my_strcat("./assets/", path),
    &rect);
    image->sprite_size = size;
    image->sprite = sfSprite_create();
    image->sprite_pos = (sfVector2f){0, 0};
    sfSprite_setTexture(image->sprite, image->texture, sfFalse);
    sfSprite_setPosition(image->sprite, image->pos);
    image->curr_pos = 0;
    image->clock_image = sfClock_create();
    return image;
}

collider_t *create_collider(int x, int y, int w, int h)
{
    collider_t *col = malloc(sizeof(collider_t));

    col->rect = malloc(sizeof(sfFloatRect));
    col->rect->left = x;
    col->rect->top = y;
    col->rect->width = w;
    col->rect->height = h;
    return col;
}

tp_t *create_tp(sfVector2f pos, sfVector2f tp_pos, int to_scene_id)
{
    tp_t *tp = malloc(sizeof(tp_t));
    tp->tp_pos = tp_pos;
    tp->to_scene_id = to_scene_id;
    tp->rect = (sfFloatRect){pos.x, pos.y, 16, 16};
    return tp;
}

void next_get_map(map_t *map, char *line)
{
    sfVector2f pos = (sfVector2f){0, 0};
    sfVector2f tp_pos = (sfVector2f){0, 0};
    int to_scene_id = 0;

    pos.x = my_getnbr(line);
    for (; line[0] != ' '; line++);
    pos.y = my_getnbr(line += 1);
    for (; line[0] != ' '; line++);
    to_scene_id = my_getnbr(line += 1);
    for (; line[0] != ' '; line++);
    tp_pos.x = my_getnbr(line += 1);
    for (; line[0] != ' '; line++);
    tp_pos.y = my_getnbr(line += 1);
    tp_t *tp = create_tp(pos, tp_pos, to_scene_id);
    push_back(&map->tp, "tp", tp, TP);
    map->nb_tp++;
}

map_t *get_map(char *map_name)
{
    FILE *fp = fopen(my_strcat(my_strcat("./assets/", map_name),
    "/data.mp"), "r");
    ssize_t read;
    size_t len = 0;
    char *line = NULL;
    map_t *map = malloc(sizeof(map_t));

    map->size = (sfVector2f){0, 0};
    getline(&line, &len, fp);
    map->name = map_name;
    map->tp = NULL;
    map->size.x = my_getnbr(line);
    for (; line[0] != ' '; line++);
    map->size.y = my_getnbr(line);
    map->nb_tp = 0;
    while ((read = getline(&line, &len, fp)) != -1)
        next_get_map(map, line);
    return map;
}
