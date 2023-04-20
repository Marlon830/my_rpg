/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** list.c
*/

#include "../../include/utils.h"
#include "../../include/scene.h"
#include <string.h>

void push_back(list_t **list, char *id, void *node, enum type type)
{
    list_t *tmp = (*list);
    list_t *new_node = malloc(sizeof(list_t));

    new_node->element = node;
    new_node->id = malloc(sizeof(char) * (my_strlen(id) + 1));
    my_strcpy(new_node->id, id);
    new_node->next = NULL;
    new_node->type = type;
    if ((*list) == NULL) {
        (*list) = new_node;
    } else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new_node;
    }
}

void delete_item(list_t **list, char *id)
{
    list_t *temp = *list;

    if (*list == NULL)
        return;
    if (temp->next == NULL)
        *list = NULL;
    while (temp->next != NULL) {
        if (my_strcmp(id, temp->next->id) == 0) {
            temp->next = temp->next->next;
            break;
        }
        temp = temp->next;
    }
}

void *get_item(list_t *list, char *id)
{
    list_t *tmp = list;

    while (tmp != NULL) {
        if (!my_strcmp(id, tmp->id))
            return tmp->element;
        tmp = tmp->next;
    }
    return NULL;
}

int get_list_len(list_t *list)
{
    list_t *temp = list;
    int i = 0;

    if (list == NULL)
        return 1;
    while (temp != NULL) {
        temp = temp->next;
        i++;
    }
    return i;
}
