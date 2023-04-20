/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inventory_list.c
*/

#include "project.h"

box_t *get_box_with_name(list_box_t *list, char *name)
{
    list_box_t *temp = list;

    while (temp != NULL) {
        if (temp->box->name != NULL && !my_strcmp(temp->box->name, name))
            return temp->box;
        temp = temp->next;
    }
    return NULL;
}

void add_new_elem_in_box(box_t *box, char *name, int type, int quantity)
{
    box->sprite = sfSprite_create();
    box->sprite_texture = sfTexture_createFromFile(name, NULL);
    sfSprite_setTexture(box->sprite, box->sprite_texture, sfTrue);
    box->pos_sprite = sfRectangleShape_getPosition(box->shape);
    sfSprite_setPosition(box->sprite, box->pos_sprite);
    box->name = malloc(sizeof(char) * (my_strlen(name) + 1));
    my_strcpy(box->name, name);
    box->quantity = quantity;
    sfText_setString(box->text, int_to_string(box->quantity));
    sfSprite_setScale(box->sprite, (sfVector2f) {0.8125, 0.8125});
    box->type_sprite = type;
}

bool add_elem(list_box_t *list, char *name, int type, int quantity)
{
    box_t *box = get_box_with_name(list, name);
    list_box_t *temp = list;

    if (box != NULL) {
        box->quantity += quantity;
        sfText_setString(box->text, int_to_string(box->quantity));
        return true;
    }
    while (temp != NULL) {
        if (temp->box->sprite == NULL) {
            add_new_elem_in_box(temp->box, name, type, quantity);
            return true;
        }
        temp = temp->next;
    }
    return false;
}

list_box_t *init_list_box(void)
{
    list_box_t *list = malloc(sizeof(*list));

    list->box = NULL;
    list->next = NULL;
    return list;
}

void add_box_to_list(list_box_t *list, box_t *box)
{
    list_box_t *temp = list;
    list_box_t *new = malloc(sizeof(*new));

    if (list->box == NULL) {
        list->box = box;
        free(new);
        return;
    }
    new->next = NULL;
    new->box = box;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}
