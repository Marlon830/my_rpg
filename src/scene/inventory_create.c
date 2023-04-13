/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inventory_create.c
*/

#include "project.h"

void create_box_bis(box_t *box)
{
    box->font = sfFont_createFromFile("assets/font/Roboto-Regular.ttf");
    box->text = sfText_create();
    sfText_setFont(box->text, box->font);
    sfText_setColor(box->text, sfWhite);
    sfText_setScale(box->text, (sfVector2f) {0.1, 0.1});
    box->is_selected = false;
    box->box_texture = sfTexture_createFromFile("assets/box.png", NULL);
    sfRectangleShape_setTexture(box->shape, box->box_texture, sfTrue);
    box->clock_box = sfClock_create();
}

box_t *create_box(sfVector2f pos, sfVector2f size, float more_x, float more_y)
{
    box_t *box = malloc(sizeof(*box));
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, sfWhite);
    sfRectangleShape_setOutlineColor(shape, sfBlack);
    box->shape = shape;
    box->more_x = more_x;
    box->more_y = more_y;
    box->sprite = NULL;
    box->sprite_texture = NULL;
    box->box_texture = NULL;
    box->quantity = 0;
    box->name = NULL;
    box->pos_animation = 0;
    box->max_animation = 0;
    create_box_bis(box);
    return box;
}

void create_boxes_in_inventory_bis(inventory_t *inventory)
{
    box_t *box;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            box = create_box((sfVector2f)
            {88 + 2 * 4 + 64 + 16 * i + 2 * i, 96 + 2 + 2 * j + 16 * j},
            (sfVector2f) {16, 16}, 2 * 5 + 64 + 16 * i + 2 * i,
            2 + 2 * j + 16 * j);
            add_box_to_list(inventory->bag, box);
        }
    }
    inventory->character = create_box((sfVector2f) {88 + 2 * 2 + 16, 96 + 2},
    (sfVector2f) {32, 64 + 3 * 2}, 2 * 2 + 16, 2);
    inventory->description = create_box((sfVector2f)
    {88 + 2, 96 + 2 * 5 + 16 * 4}, (sfVector2f) {64 + 2 * 2, 48 + 2 * 2},
    2, 2 * 5 + 16 * 4);
    create_box_des_char(inventory->description, 1);
    create_box_des_char(inventory->character, 2);
}

void create_boxes_in_inventory(inventory_t *inventory)
{
    box_t *box;

    for (int i = 0; i < 4; i++) {
        box = create_box((sfVector2f) {88 + 2, 96 + 2 + 2 * i + 16 * i},
        (sfVector2f) {16, 16}, 2, 2 + 2 * i + 16 * i);
        add_box_to_list(inventory->first_equipment, box);
    }
    for (int i = 0; i < 4; i++) {
        box = create_box((sfVector2f)
        {88 + 2 * 3 + 48, 96 + 2 + 2 * i + 16 * i},
        (sfVector2f) {16, 16}, 2 * 3 + 48, 2 + 2 * i + 16 * i);
        add_box_to_list(inventory->second_equipment, box);
    }
    create_boxes_in_inventory_bis(inventory);
}

inventory_t *create_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(*inventory));
    sfVector2f pos = {80 + 8, 80 + 16};
    sfVector2f size = {128 + 2 * 9, 112 + 2 * 8};

    inventory->first_equipment = init_list_box();
    inventory->second_equipment = init_list_box();
    inventory->bag = init_list_box();
    inventory->is_active = false;
    inventory->shape = sfRectangleShape_create();
    inventory->texture = sfTexture_createFromFile("assets/inventory.png", NULL);
    sfRectangleShape_setPosition(inventory->shape, pos);
    sfRectangleShape_setSize(inventory->shape, size);
    sfRectangleShape_setFillColor(inventory->shape, sfWhite);
    sfRectangleShape_setOutlineColor(inventory->shape, sfBlack);
    sfRectangleShape_setTexture(inventory->shape, inventory->texture, sfTrue);
    create_boxes_in_inventory(inventory);
    return inventory;
}
