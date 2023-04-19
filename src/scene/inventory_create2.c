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

void modify_type_box2(inventory_t *inventory, int type_box,
char *list_texture[7], int count)
{
    list_box_t *temp = inventory->second_equipment;

    for (int i = 0; i < 4; i++) {
        temp->box->special_texture = sfTexture_createFromFile(
        list_texture[count], NULL);
        sfRectangleShape_setTexture(temp->box->shape,
        temp->box->special_texture, sfTrue);
        temp->box->is_special = true;
        temp->box->type_box = type_box;
        type_box++;
        temp = temp->next;
        count++;
    }
}

void modify_type_box(inventory_t *inventory)
{
    list_box_t *temp = inventory->first_equipment;
    int type_box = HELMET;
    char *list_texture[9] = {"assets/box_helmet.png", "assets/box_armor.png",
    "assets/box_pants.png", "assets/box_boots.png", "assets/box_amulet.png",
    "assets/box_ring.png", "assets/box_sword.png", "assets/box_shield.png",
    NULL};
    int count = 0;

    while (temp != NULL) {
        temp->box->special_texture = sfTexture_createFromFile(
            list_texture[count], NULL);
        sfRectangleShape_setTexture(temp->box->shape,
        temp->box->special_texture, sfTrue);
        temp->box->is_special = true;
        temp->box->type_box = type_box;
        type_box++;
        temp = temp->next;
        count++;
    }
    modify_type_box2(inventory, type_box, list_texture, count);
}
