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
        box->max_animation = 3;
        rect = (sfIntRect) {0, 0, 32, 32};
        sfTexture_destroy(box->box_texture);
        box->sprite = sfSprite_create();
        box->sprite_texture = sfTexture_createFromFile("assets/player.png",
        &rect);
        sfSprite_setTexture(box->sprite, box->sprite_texture, sfTrue);
        box->box_texture = sfTexture_createFromFile("assets/character_box.png",
        NULL);
        sfRectangleShape_setTexture(box->shape, box->box_texture, sfTrue);
    }
}

void modify_type_box(inventory_t *inventory)
{
    list_box_t *temp = inventory->first_equipment;
    int type_box = HELMET;

    while (temp != NULL) {
        temp->box->type_box = type_box;
        type_box++;
        temp = temp->next;
    }
    temp = inventory->second_equipment;
    temp = temp->next;
    for (int i = 0; i < 2; i++) {
        temp->box->type_box = type_box;
        type_box++;
        temp = temp->next;
    }
}
