/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_inventory3.c
*/

#include "project.h"

char *get_description_elem(box_t *box)
{
    char *path = malloc(my_strlen(box->name) + 12);
    int i = my_strlen(box->name) - 1;

    my_strcpy(path, "assets/description/");
    for (; box->name[i] != '/'; i--);
    my_strcpy(path + my_strlen(path), box->name + i);
    my_strcpy(path + my_strlen(path) - 3, "txt");
    return path;
}

void update_description(project_t *project, inventory_t *inventory, box_t *box)
{
    char *buffer = get_file(get_description_elem(box));
    sfVector2f pos =
    sfRectangleShape_getPosition(inventory->description->shape);

    if (buffer != NULL) {
        sfText_setScale(inventory->description->text, (sfVector2f) {0.1, 0.1});
        sfText_setString(inventory->description->text, buffer);
        sfText_setPosition(inventory->description->text, (sfVector2f)
        {pos.x + 1, pos.y + 1});
        sfRenderWindow_drawText(WINDOW, inventory->description->text, NULL);
    }
    sfSprite_setPosition(box->hover, (sfVector2f) {project->player->pos.x - 72
    + box->more_x, project->player->pos.y - 64 + box->more_y});
    sfRenderWindow_drawSprite(WINDOW, box->hover, NULL);
}

void update_hover_or_selected_box(project_t *project, box_t *box)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(WINDOW);
    sfVector2f new_pos = convert_mouse_position(project, (sfVector2f)
    {pos.x, pos.y});
    sfVector2f pos_box = sfRectangleShape_getPosition(box->shape);
    sfVector2f size_box = sfRectangleShape_getSize(box->shape);

    if (box->is_selected) {
        update_description(project, project->inventory, box);
        return;
    }
    if (project->inventory->box_selected)
        return;
    if (new_pos.x >= pos_box.x && new_pos.x <= pos_box.x + size_box.x &&
    new_pos.y >= pos_box.y && new_pos.y <= pos_box.y + size_box.y) {
        if (box->sprite != NULL)
            update_description(project, project->inventory, box);
    }
}

int unequip_equipment(project_t *project, box_t *equip_box)
{
    box_t *empty_box = get_empty_box(project->inventory);

    if (empty_box == NULL)
        return 0;
    change_elem_box(project, empty_box, equip_box);
    return 0;
}

int check_shift_click(project_t *project, box_t *box)
{
    box_t *good_box;

    if (!project->inventory->shift_pressed || box == NULL ||
    box->sprite == NULL || box->type_sprite == OTHER)
        return 0;
    good_box = get_box_with_type(project->inventory, box->type_sprite);
    if (good_box->sprite != NULL && my_strcmp(good_box->name, box->name) == 0)
        return unequip_equipment(project, box);
    if (good_box->sprite == NULL) {
        change_elem_box(project, good_box, box);
        return 1;
    }
    switch_elem_box(project, good_box, box);
    return 1;
}
