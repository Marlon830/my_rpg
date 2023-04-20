/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** image_destroy.c
*/

#include "scene.h"

void destroy_image(image_t *image)
{
    sfSprite_destroy(image->sprite);
    sfTexture_destroy(image->texture);
    sfClock_destroy(image->clock_image);
    free(image);
}
