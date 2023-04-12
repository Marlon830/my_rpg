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
    sfTexture *texture = sfTexture_createFromFile("assets/box-dialog.png",
    &(sfIntRect){0, 0, 200, 30});

    sfRectangleShape_setSize(rect, (sfVector2f) {200, 30});
    sfRectangleShape_setTexture(rect, texture, sfFalse);
    return rect;
}
