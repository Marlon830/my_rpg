/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** graphic_draw.c
*/

#include "../../include/graphic.h"

void images_draw(graphic_t *graphic)
{
    list_t *tmp = graphic->images;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(graphic->window,
        ((image_t *)tmp->element)->sprite, NULL);
        tmp = tmp->next;
    }
}

void graphic_draw(graphic_t *graphic)
{
    sfRenderWindow_clear(graphic->window, sfBlack);
    images_draw(graphic);
}
