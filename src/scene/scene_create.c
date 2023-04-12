/*
** EPITECH PROJECT, 2022
** tiled-to-c
** File description:
** scene_create.c
*/

#include "../../include/scene.h"
#include "../../include/utils.h"
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

sfText *create_text(void)
{
    sfText *text;
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setScale(text, (sfVector2f) {0.3, 0.3});
    sfText_setPosition(text, (sfVector2f) {160, 160});
    return text;
}

sfRectangleShape *create_rect(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, sfBlack);
    sfRectangleShape_setSize(rect, (sfVector2f) {200, 30});
    return rect;
}
