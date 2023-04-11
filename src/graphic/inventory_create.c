/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inventory_create.c
*/

#include "project.h"

void add_box_to_list(list_box_t *list, box_t *box)
{
    list_box_t *temp = list;
    list_box_t *new = malloc(sizeof(*new));

    if (list->box == NULL) {
        list->box = box;
        free(new);
        return;
    }
    new->next = NULL;
    new->box = box;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}

box_t *create_box(sfVector2f pos, sfVector2f size)
{
    box_t *box = malloc(sizeof(*box));
    sfRectangleShape *shape = sfRectangleShape_create();

    box->pos_box = pos;
    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, (sfColor) {112, 114, 110, 255});
    sfRectangleShape_setOutlineColor(shape, sfBlack);
    box->shape = shape;
    return box;
}

list_box_t *init_list_box(void)
{
    list_box_t *list = malloc(sizeof(*list));

    list->box = NULL;
    list->next = NULL;
    return list;
}

void create_boxes(inventory_t *inventory)
{
    for (int i = 0; i < 4; i++)
        add_box_to_list(inventory->first_equipment, create_box((sfVector2f)
        {112 + 2, 104 + 2 + 2 * i + 16 * i}, (sfVector2f) {16, 16}));
    for (int i = 0; i < 4; i++)
        add_box_to_list(inventory->second_equipment, create_box((sfVector2f)
        {112 + 2 * 3 + 48, 104 + 2 + 2 * i + 16 * i}, (sfVector2f) {16, 16}));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++)
            add_box_to_list(inventory->bag, create_box((sfVector2f)
            {112 + 2 * 4 + 64 + 16 * i + 2 * i, 104 + 2 + 2 * j + 16 * j},
            (sfVector2f) {16, 16}));
    }
    inventory->character = create_box((sfVector2f) {112 + 2 * 2 + 16, 104 + 2},
    (sfVector2f) {32, 64 + 3 * 2});
    inventory->description = create_box((sfVector2f)
    {112 + 2, 104 + 2 * 5 + 16 * 4}, (sfVector2f) {64 + 2 * 2, 48 + 2 * 2});
}

inventory_t *create_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(*inventory));
    sfVector2f pos = {80 + 32, 80 + 24};
    sfVector2f size = {128 + 2 * 8, 112 + 2 * 8};

    inventory->first_equipment = init_list_box();
    inventory->second_equipment = init_list_box();
    inventory->bag = init_list_box();
    inventory->is_active = false;
    inventory->shape = sfRectangleShape_create();
    sfRectangleShape_setPosition(inventory->shape, pos);
    sfRectangleShape_setSize(inventory->shape, size);
    sfRectangleShape_setFillColor(inventory->shape, (sfColor)
    {196, 201, 199, 255});
    sfRectangleShape_setOutlineColor(inventory->shape, sfBlack);
    create_boxes(inventory);
    return inventory;
}
