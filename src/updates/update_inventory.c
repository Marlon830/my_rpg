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

void update_box(project_t *project, box_t *box)
{
    sfVector2f pos_box;

    sfRectangleShape_setPosition(box->shape, (sfVector2f)
    {project->player->pos.x - 72 + box->more_x,
    project->player->pos.y - 64 + box->more_y});
    sfRenderWindow_drawRectangleShape(WINDOW, box->shape, NULL);
    if (box->sprite != NULL) {
        pos_box = sfRectangleShape_getPosition(box->shape);
        box->pos_sprite = pos_box;
        sfSprite_setPosition(box->sprite, box->pos_sprite);
        sfText_setPosition(box->text, (sfVector2f) {pos_box.x + 0.5,
        pos_box.y + 12.5});
        sfRenderWindow_drawSprite(WINDOW, box->sprite, NULL);
        sfRenderWindow_drawText(WINDOW, box->text, NULL);
    }
}

void update_list_box(project_t *project, list_box_t *list)
{
    list_box_t *temp = list;

    if (list->box == NULL)
        return;
    update_box(project, list->box);
    temp = temp->next;
    while (temp != NULL) {
        update_box(project, temp->box);
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
