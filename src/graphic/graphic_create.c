/*
** EPITECH PROJECT, 2022
** tiled-to-c
** File description:
** graphic_create.c
*/

#include "../../include/graphic.h"
#include "../../include/utils.h"
#include <string.h>

image_t *create_image(int x, int y, char *path, sfIntRect rect)
{
    image_t *image = malloc(sizeof(image_t));

    image->pos = (sfVector2f){(float)x, (float)y};
    image->texture = sfTexture_createFromFile(my_strcat("./assets/", path),
    &rect);
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, image->texture, sfFalse);
    sfSprite_setPosition(image->sprite, image->pos);
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
