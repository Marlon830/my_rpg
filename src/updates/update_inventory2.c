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
