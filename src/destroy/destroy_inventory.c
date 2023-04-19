/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_inventory.c
*/

#include "project.h"

void destroy_box2(box_t *box)
{
    if (box->font != NULL)
        sfFont_destroy(box->font);
    if (box->clock_box != NULL)
        sfClock_destroy(box->clock_box);
    free(box);
}

void destroy_box(box_t *box)
{
    if (box->shape != NULL)
        sfRectangleShape_destroy(box->shape);
    if (box->sprite != NULL)
        sfSprite_destroy(box->sprite);
    if (box->sprite_texture != NULL)
        sfTexture_destroy(box->sprite_texture);
    if (box->box_texture != NULL)
        sfTexture_destroy(box->box_texture);
    if (box->special_texture != NULL)
        sfTexture_destroy(box->special_texture);
    if (box->hover != NULL)
        sfSprite_destroy(box->hover);
    if (box->hover_texture != NULL)
        sfTexture_destroy(box->hover_texture);
    if (box->name != NULL)
        free(box->name);
    if (box->text != NULL)
        sfText_destroy(box->text);
    destroy_box2(box);
}

void destroy_list_box(list_box_t *list)
{
    list_box_t *temp = list->next;
    list_box_t *temp2 = list;

    while (temp->next != NULL) {
        destroy_box(temp2->box);
        free(temp2);
        temp2 = temp;
        temp = temp->next;
    }
    destroy_box(temp->box);
    free(temp);
}

void destroy_inventory(inventory_t *inventory)
{
    sfRectangleShape_destroy(inventory->shape);
    sfTexture_destroy(inventory->texture);
    destroy_list_box(inventory->first_equipment);
    destroy_list_box(inventory->second_equipment);
    destroy_list_box(inventory->bag);
    destroy_box(inventory->character);
    destroy_box(inventory->description);
}
