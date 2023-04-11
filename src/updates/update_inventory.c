/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_inventory.c
*/

#include "project.h"

void switch_state_inventory(inventory_t *inventory)
{
    if (inventory->is_active)
        inventory->is_active = false;
    else
        inventory->is_active = true;
}

void update_list_box(project_t *project, list_box_t *list)
{
    list_box_t *temp = list;

    if (list->box == NULL)
        return;
    sfRenderWindow_drawRectangleShape(WINDOW, list->box->shape, NULL);
    temp = temp->next;
    while (temp != NULL) {
        sfRenderWindow_drawRectangleShape(WINDOW, temp->box->shape, NULL);
        temp = temp->next;
    }
}

void update_inventory(project_t *project)
{
    if (!project->inventory->is_active)
        return;
    sfRenderWindow_drawRectangleShape(WINDOW, project->inventory->shape, NULL);
    update_list_box(project, project->inventory->first_equipment);
    update_list_box(project, project->inventory->second_equipment);
    update_list_box(project, project->inventory->bag);
    sfRenderWindow_drawRectangleShape(WINDOW,
    project->inventory->character->shape, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW,
    project->inventory->description->shape, NULL);
}
