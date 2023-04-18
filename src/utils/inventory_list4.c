/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inventory_list4.c
*/

#include "project.h"

box_t *get_box_with_type(inventory_t *inventory, int type)
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
