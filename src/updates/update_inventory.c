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
    sfRectangleShape_setPosition(list->box->shape, (sfVector2f)
    {project->player->pos.x - 72 + list->box->more_x,
    project->player->pos.y - 64 + list->box->more_y});
    sfRenderWindow_drawRectangleShape(WINDOW, list->box->shape, NULL);
    temp = temp->next;
    while (temp != NULL) {
        sfRectangleShape_setPosition(temp->box->shape, (sfVector2f)
        {project->player->pos.x - 72 + temp->box->more_x,
        project->player->pos.y - 64 + temp->box->more_y});
        sfRenderWindow_drawRectangleShape(WINDOW, temp->box->shape, NULL);
        temp = temp->next;
    }
}

void update_inventory(project_t *project)
{
    if (!project->inventory->is_active)
        return;
    sfRectangleShape_setPosition(project->inventory->shape, (sfVector2f)
    {project->player->pos.x - 72, project->player->pos.y - 64});
    sfRenderWindow_drawRectangleShape(WINDOW, project->inventory->shape, NULL);
    update_list_box(project, project->inventory->first_equipment);
    update_list_box(project, project->inventory->second_equipment);
    update_list_box(project, project->inventory->bag);
    sfRectangleShape_setPosition(project->inventory->character->shape,
    (sfVector2f) {project->player->pos.x - 72 +
    project->inventory->character->more_x, project->player->pos.y - 64 +
    project->inventory->character->more_y});
    sfRenderWindow_drawRectangleShape(WINDOW,
    project->inventory->character->shape, NULL);
    sfRectangleShape_setPosition(project->inventory->description->shape,
    (sfVector2f) {project->player->pos.x - 72 +
    project->inventory->description->more_x, project->player->pos.y - 64 +
    project->inventory->description->more_y});
    sfRenderWindow_drawRectangleShape(WINDOW,
    project->inventory->description->shape, NULL);
}
