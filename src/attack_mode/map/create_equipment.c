/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_equipment.c
*/

#include "project.h"

void set_texture_equipment2(equipment_t *equip)
{
    if (equip->amulet != NULL) {
        sfSprite_setScale(equip->amulet, (sfVector2f) {5, 5});
        sfSprite_setOrigin(equip->amulet, (sfVector2f) {17, 24});
    }
    if (equip->ring != NULL) {
        sfSprite_setScale(equip->ring, (sfVector2f) {5, 5});
        sfSprite_setOrigin(equip->ring, (sfVector2f) {17, 24});
    }
    if (equip->sword != NULL) {
        sfSprite_setScale(equip->sword, (sfVector2f) {5, 5});
        sfSprite_setOrigin(equip->sword, (sfVector2f) {17, 24});
    }
    if (equip->shield != NULL) {
        sfSprite_setScale(equip->shield, (sfVector2f) {5, 5});
        sfSprite_setOrigin(equip->shield, (sfVector2f) {17, 24});
    }
}

void set_texture_equipment(equipment_t *equip)
{
    if (equip->helmet != NULL) {
        sfSprite_setScale(equip->helmet, (sfVector2f) {5, 5});
        sfSprite_setOrigin(equip->helmet, (sfVector2f) {17, 24});
    }
    if (equip->armor != NULL) {
        sfSprite_setScale(equip->armor, (sfVector2f) {5, 5});
        sfSprite_setOrigin(equip->armor, (sfVector2f) {17, 24});
    }
    if (equip->pants != NULL) {
        sfSprite_setScale(equip->pants, (sfVector2f) {5, 5});
        sfSprite_setOrigin(equip->pants, (sfVector2f) {17, 24});
    }
    if (equip->boots != NULL) {
        sfSprite_setScale(equip->boots, (sfVector2f) {5, 5});
        sfSprite_setOrigin(equip->boots, (sfVector2f) {17, 24});
    }
    set_texture_equipment2(equip);
}
