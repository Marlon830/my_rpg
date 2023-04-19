/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inventory_list2.c
*/

#include "project.h"

void reset_box(box_t *box)
{
    sfTexture_destroy(box->sprite_texture);
    box->sprite_texture = NULL;
    sfSprite_destroy(box->sprite);
    box->sprite = NULL;
    free(box->name);
    box->name = NULL;
    box->quantity = 0;
    box->is_selected = 0;
    box->type_sprite = NO_OBJECT;
}

void delete_elem(list_box_t *list, char *name, int quantity)
{
    list_box_t *temp = list;

    while (temp != NULL) {
        if (temp->box->sprite == NULL) {
            temp = temp->next;
            continue;
        }
        if (!my_strcmp(temp->box->name, name) &&
        temp->box->quantity - quantity > 0) {
            temp->box->quantity -= quantity;
            sfText_setString(temp->box->text,
            int_to_string(temp->box->quantity));
            return;
        }
        if (!my_strcmp(temp->box->name, name)) {
            reset_box(temp->box);
            return;
        }
        temp = temp->next;
    }
}

bool check_box_with_coord(box_t *box, sfVector2f pos)
{
    sfVector2f pos_box = sfRectangleShape_getPosition(box->shape);
    sfVector2f size_box = sfRectangleShape_getSize(box->shape);

    if (pos.x >= pos_box.x && pos.x <= pos_box.x + size_box.x &&
    pos.y >= pos_box.y && pos.y <= pos_box.y + size_box.y)
        return true;
    return false;
}

box_t *get_box_with_coord(project_t *project, sfVector2f pos)
{
    list_box_t *temp = project->inventory->bag;

    while (temp != NULL) {
        if (check_box_with_coord(temp->box, pos))
            return temp->box;
        temp = temp->next;
    }
    temp = project->inventory->first_equipment;
    while (temp != NULL) {
        if (check_box_with_coord(temp->box, pos))
            return temp->box;
        temp = temp->next;
    }
    temp = project->inventory->second_equipment;
    while (temp != NULL) {
        if (check_box_with_coord(temp->box, pos))
            return temp->box;
        temp = temp->next;
    }
    return NULL;
}

void select_box(project_t *project, sfVector2f pos)
{
    sfVector2f new_pos = convert_mouse_position(project, pos);
    box_t *box = get_box_with_coord(project, new_pos);

    if (check_shift_click(project, box))
        return;
    if (box != NULL && box->sprite != NULL) {
        box->is_selected = true;
        project->inventory->state = PRESSED;
        project->inventory->box_selected = true;
    }
}
