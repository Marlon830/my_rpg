/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inventory_list4.c
*/

#include "project.h"

int get_good_path(char *name)
{
    int pos = my_strlen(name) - 1;

    while (name[pos] != '/')
        pos = pos - 1;
    return pos + 1;
}

box_t *get_box_with_type(inventory_t *inventory, enum object_type type)
{
    list_box_t *temp = inventory->first_equipment;

    while (temp != NULL) {
        if (temp->box->type_box == type)
            return temp->box;
        temp = temp->next;
    }
    temp = inventory->second_equipment;
    while (temp != NULL) {
        if (temp->box->type_box == type)
            return temp->box;
        temp = temp->next;
    }
    return NULL;
}

box_t *get_empty_box(inventory_t *inventory)
{
    list_box_t *temp = inventory->bag;

    while (temp != NULL) {
        if (temp->box->sprite == NULL)
            return temp->box;
        temp = temp->next;
    }
    return NULL;
}
