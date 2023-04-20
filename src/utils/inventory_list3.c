/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inventory_list3.c
*/

#include "project.h"

box_t *get_box_selected(project_t *project)
{
    list_box_t *temp = project->inventory->bag;

    while (temp != NULL) {
        if (temp->box->is_selected)
            return temp->box;
        temp = temp->next;
    }
    temp = project->inventory->first_equipment;
    while (temp != NULL) {
        if (temp->box->is_selected)
            return temp->box;
        temp = temp->next;
    }
    temp = project->inventory->second_equipment;
    while (temp != NULL) {
        if (temp->box->is_selected)
            return temp->box;
        temp = temp->next;
    }
    return NULL;
}

void change_elem_box(project_t *project, box_t *new_box, box_t *selected_box)
{
    add_or_delete_stat(project, new_box, selected_box);
    add_new_elem_in_box(new_box, selected_box->name, selected_box->type_sprite,
    selected_box->quantity);
    reset_box(selected_box);
    update_equipment(project, project->inventory);
}

void switch_elem_box(project_t *project, box_t *new_box, box_t *selected_box)
{
    char *temp_str = malloc(my_strlen(new_box->name) + 1);
    int temp_quantity = new_box->quantity;
    int temp_type = new_box->type_sprite;

    if (selected_box->type_box != OTHER && new_box->type_sprite !=
    selected_box->type_box) {
        selected_box->is_selected = false;
        return;
    }
    switch_stat(project, new_box, selected_box);
    my_strcpy(temp_str, new_box->name);
    reset_box(new_box);
    add_new_elem_in_box(new_box, selected_box->name, selected_box->type_sprite,
    selected_box->quantity);
    reset_box(selected_box);
    add_new_elem_in_box(selected_box, temp_str, temp_type, temp_quantity);
    update_equipment(project, project->inventory);
}

void unselect_box(project_t *project, sfVector2f pos)
{
    box_t *selected_box = get_box_selected(project);
    sfVector2f new_pos = convert_mouse_position(project, pos);
    box_t *new_box = get_box_with_coord(project, new_pos);

    project->inventory->state = NONE2;
    project->inventory->box_selected = false;
    if (selected_box == NULL)
        return;
    if (new_box == NULL || (new_box->sprite != NULL &&
    !my_strcmp(new_box->name, selected_box->name)) ||
    (new_box->type_box != OTHER && selected_box->type_sprite
    != new_box->type_box)) {
        selected_box->is_selected = false;
        return;
    }
    if (new_box->sprite != NULL) {
        switch_elem_box(project, new_box, selected_box);
        return;
    }
    change_elem_box(project, new_box, selected_box);
}

sfVector2f convert_mouse_position(project_t *project, sfVector2f pos)
{
    sfVector2f center = sfView_getCenter(project->scene->camera);
    sfVector2f size = sfView_getSize(project->scene->camera);
    sfVector2f top_left = (sfVector2f) {center.x - size.x / 2,
    center.y - size.y / 2};
    sfVector2u window_size = sfRenderWindow_getSize(WINDOW);
    sfVector2f new_coord;

    new_coord.x = size.x * pos.x / window_size.x + top_left.x;
    new_coord.y = size.y * pos.y / window_size.y + top_left.y;
    return new_coord;
}
