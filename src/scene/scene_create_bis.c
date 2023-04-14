/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** scene_create_bis.c
*/

#include "scene.h"
#include "utils.h"
#include "project.h"
#include <string.h>

tp_t *create_tp(sfVector2f pos, sfVector2f tp_pos, int to_scene_id)
{
    tp_t *tp = malloc(sizeof(tp_t));
    tp->tp_pos = tp_pos;
    tp->to_scene_id = to_scene_id;
    tp->rect = (sfFloatRect){pos.x, pos.y, 16, 16};
    return tp;
}

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

sfText *create_text(sfVector2f pos, sfVector2f size, sfColor color)
{
    sfText *text;
    sfFont *font = sfFont_createFromFile("assets/font.otf");

    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setScale(text, size);
    sfText_setPosition(text, pos);
    sfText_setFillColor(text, color);
    return text;
}

sfRectangleShape *create_rect(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile("assets/box-dialog.png",
    &(sfIntRect){0, 0, 200, 30});

    sfRectangleShape_setSize(rect, (sfVector2f) {200, 30});
    sfRectangleShape_setTexture(rect, texture, sfFalse);
    return rect;
}
