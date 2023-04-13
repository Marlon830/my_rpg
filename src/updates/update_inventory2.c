/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_inventory2.c
*/

#include "project.h"

void switch_state_inventory(inventory_t *inventory)
{
    if (inventory->is_active)
        inventory->is_active = false;
    else
        inventory->is_active = true;
}

void update_selected_box(project_t *project)
{
    box_t *box = get_box_selected(project);

    if (box == NULL)
        return;
    sfRenderWindow_drawSprite(WINDOW, box->sprite, NULL);
}

void update_inventory_character(project_t *project, box_t *box)
{
    sfRectangleShape_setPosition(box->shape,
    (sfVector2f) {project->player->pos.x - 72 +
    box->more_x, project->player->pos.y - 64 +
    box->more_y});
    sfRenderWindow_drawRectangleShape(WINDOW,
    box->shape, NULL);
    sfSprite_setPosition(box->sprite, (sfVector2f)
    {project->player->pos.x - 72 + box->more_x,
    project->player->pos.y - 64 + box->more_y + 16});
    sfRenderWindow_drawSprite(WINDOW, box->sprite, NULL);
}

void update_inventory_description(project_t *project, box_t *box)
{
    sfRectangleShape_setPosition(box->shape,
    (sfVector2f) {project->player->pos.x - 72 +
    box->more_x, project->player->pos.y - 64 +
    box->more_y});
    sfRenderWindow_drawRectangleShape(WINDOW,
    box->shape, NULL);
}
