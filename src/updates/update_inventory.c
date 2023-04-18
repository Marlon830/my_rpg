/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_inventory.c
*/

#include "project.h"

void update_box_bis(project_t *project, box_t *box, sfVector2f new_mouse_pos)
{
    sfVector2f pos_box = sfRectangleShape_getPosition(box->shape);

    if (box->is_selected)
        box->pos_sprite = (sfVector2f) {new_mouse_pos.x - 6,
        new_mouse_pos.y - 6};
    if (!box->is_selected) {
        box->pos_sprite.x = pos_box.x + 1.5;
        box->pos_sprite.y = pos_box.y;
    }
    sfSprite_setPosition(box->sprite, box->pos_sprite);
    sfText_setPosition(box->text, (sfVector2f) {pos_box.x + 1.25,
    pos_box.y + 11.75});
    sfRenderWindow_drawSprite(WINDOW, box->sprite, NULL);
    sfRenderWindow_drawText(WINDOW, box->text, NULL);
}

void update_box(project_t *project, box_t *box)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(WINDOW);
    sfVector2f new_mouse_pos = convert_mouse_position(project, (sfVector2f)
    {mouse_pos.x, mouse_pos.y});

    sfRectangleShape_setTexture(box->shape, box->box_texture, sfTrue);
    sfRectangleShape_setPosition(box->shape, (sfVector2f)
    {project->player->pos.x - 72 + box->more_x,
    project->player->pos.y - 64 + box->more_y});
    if (box->is_special && box->sprite == NULL) {
        sfRectangleShape_setTexture(box->shape, box->special_texture, sfTrue);
    }
    sfRenderWindow_drawRectangleShape(WINDOW, box->shape, NULL);
    update_hover_or_selected_box(project, box);
    if (box->sprite != NULL)
        update_box_bis(project, box, new_mouse_pos);
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

void update_inventory_bis(project_t *project)
{
    sfRectangleShape_setPosition(project->inventory->shape, (sfVector2f)
    {project->player->pos.x - 72, project->player->pos.y - 64});
    sfRenderWindow_drawRectangleShape(WINDOW, project->inventory->shape, NULL);
    update_inventory_description(project, project->inventory->description);
    update_inventory_character(project, project->inventory->character);
    update_list_box(project, project->inventory->first_equipment);
    update_list_box(project, project->inventory->second_equipment);
    update_list_box(project, project->inventory->bag);
    update_selected_box(project);
}

void update_inventory(project_t *project)
{
    if (!project->inventory->is_active)
        return;
    update_inventory_bis(project);
}
