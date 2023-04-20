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
    update_hover_or_selected_box(project, box);
    sfRenderWindow_drawSprite(WINDOW, box->sprite, NULL);
}

void animate_inventory_sprite(box_t *box)
{
    sfIntRect rect;

    box->time_box = sfClock_getElapsedTime(box->clock_box);
    box->seconds_box = box->time_box.microseconds / 1000000.0;
    if (box->seconds_box <= 0.15)
        return;
    if (box->pos_animation == box->max_animation)
        box->pos_animation = 0;
    else
        box->pos_animation++;
    rect = (sfIntRect) {box->pos_animation * 32, 0, 32, 32};
    sfTexture_destroy(box->sprite_texture);
    box->sprite_texture = sfTexture_createFromFile("assets/player.png", &rect);
    sfSprite_setTexture(box->sprite, box->sprite_texture, sfTrue);
    sfClock_restart(box->clock_box);
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
    animate_inventory_sprite(project->inventory->character);
    sfRenderWindow_drawSprite(WINDOW, box->sprite, NULL);
    update_equipment_inventory_sprite(project, box, project->player);
    update_stats(project, (sfVector2f){project->player->pos.x,
    project->player->pos.y}, (sfVector2f){.2, .2});
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
