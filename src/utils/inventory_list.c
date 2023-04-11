/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inventory_list.c
*/

#include "project.h"

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
