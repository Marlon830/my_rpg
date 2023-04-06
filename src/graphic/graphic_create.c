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
    image->texture = sfTexture_createFromFile(cat("./assets/", path), &rect);
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, image->texture, sfFalse);
    sfSprite_setPosition(image->sprite, image->pos);
    return image;
}
