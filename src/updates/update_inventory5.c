/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_inventory5.c
*/

#include "project.h"

void update_equipment_inventory_sprite4(project_t *project, box_t *character,
equipment_t *equipment, sfVector2f pos)
{
    if (equipment->sword != NULL) {
        sfSprite_setPosition(equipment->sword, pos);
        sfSprite_setTextureRect(equipment->sword, (sfIntRect)
        {character->pos_animation * 32, 0, 32, 32});
        sfRenderWindow_drawSprite(WINDOW, equipment->sword, NULL);
    }
    if (equipment->shield != NULL) {
        sfSprite_setPosition(equipment->shield, pos);
        sfSprite_setTextureRect(equipment->shield, (sfIntRect)
        {character->pos_animation * 32, 0, 32, 32});
        sfRenderWindow_drawSprite(WINDOW, equipment->shield, NULL);
    }
}

void update_equipment_inventory_sprite3(project_t *project, box_t *character,
equipment_t *equipment, sfVector2f pos)
{
    if (equipment->amulet != NULL) {
        sfSprite_setPosition(equipment->amulet, pos);
        sfSprite_setTextureRect(equipment->amulet, (sfIntRect)
        {character->pos_animation * 32, 0, 32, 32});
        sfRenderWindow_drawSprite(WINDOW, equipment->amulet, NULL);
    }
    if (equipment->ring != NULL) {
        sfSprite_setPosition(equipment->ring, pos);
        sfSprite_setTextureRect(equipment->ring, (sfIntRect)
        {character->pos_animation * 32, 0, 32, 32});
        sfRenderWindow_drawSprite(WINDOW, equipment->ring, NULL);
    }
    update_equipment_inventory_sprite4(project, character, equipment, pos);
}

void update_equipment_inventory_sprite2(project_t *project, box_t *character,
equipment_t *equipment, sfVector2f pos)
{
    if (equipment->pants != NULL) {
        sfSprite_setPosition(equipment->pants, pos);
        sfSprite_setTextureRect(equipment->pants, (sfIntRect)
        {character->pos_animation * 32, 0, 32, 32});
        sfRenderWindow_drawSprite(WINDOW, equipment->pants, NULL);
    }
    if (equipment->boots != NULL) {
        sfSprite_setPosition(equipment->boots, pos);
        sfSprite_setTextureRect(equipment->boots, (sfIntRect)
        {character->pos_animation * 32, 0, 32, 32});
        sfRenderWindow_drawSprite(WINDOW, equipment->boots, NULL);
    }
    update_equipment_inventory_sprite3(project, character, equipment, pos);
}

void update_equipment_inventory_sprite(project_t *project, box_t *character,
player_t *player)
{
    equipment_t *equipment = player->equipment;
    sfVector2f pos = (sfVector2f) {player->pos.x - 72 + character->more_x,
    player->pos.y - 64 + character->more_y + 16};

    if (equipment->helmet != NULL) {
        sfSprite_setPosition(equipment->helmet, pos);
        sfSprite_setTextureRect(equipment->helmet, (sfIntRect)
        {character->pos_animation * 32, 0, 32, 32});
        sfRenderWindow_drawSprite(WINDOW, equipment->helmet, NULL);
    }
    if (equipment->armor != NULL) {
        sfSprite_setPosition(equipment->armor, pos);
        sfSprite_setTextureRect(equipment->armor, (sfIntRect)
        {character->pos_animation * 32, 0, 32, 32});
        sfRenderWindow_drawSprite(WINDOW, equipment->armor, NULL);
    }
    update_equipment_inventory_sprite2(project, character, equipment, pos);
}
