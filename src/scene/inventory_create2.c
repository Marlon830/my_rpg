/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inventory_create2.c
*/

#include "project.h"

void create_box_des_char(box_t *box, int des_char)
{
    sfIntRect rect;

    if (des_char == 1) {
        sfTexture_destroy(box->box_texture);
        box->box_texture = sfTexture_createFromFile(
            "assets/description_box.png", NULL);
        sfRectangleShape_setTexture(box->shape, box->box_texture, sfTrue);
    }
    if (des_char == 2) {
        rect = (sfIntRect) {0, 0, 16, 16};
        sfTexture_destroy(box->box_texture);
        box->sprite = sfSprite_create();
        box->sprite_texture = sfTexture_createFromFile("assets/player.png",
        &rect);
        sfSprite_setTexture(box->sprite, box->sprite_texture, sfTrue);
        sfSprite_setScale(box->sprite, (sfVector2f) {2, 2});
        box->box_texture = sfTexture_createFromFile("assets/character_box.png",
        NULL);
        sfRectangleShape_setTexture(box->shape, box->box_texture, sfTrue);
    }
}
