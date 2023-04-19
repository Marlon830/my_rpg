/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_manager2.c
*/

#include "project.h"

void modify_sword(player_t *player, char *path)
{
    equipment_t *equipment = player->equipment;

    if (path == NULL) {
        sfSprite_destroy(equipment->sword);
        sfTexture_destroy(equipment->sword_texture);
        equipment->sword = NULL;
        equipment->sword_texture = NULL;
        free(path);
        return;
    }
    if (equipment->sword != NULL) {
        sfSprite_destroy(equipment->sword);
        sfTexture_destroy(equipment->sword_texture);
    }
    equipment->sword = sfSprite_create();
    equipment->sword_texture = sfTexture_createFromFile(path, &(sfIntRect)
    {0, 0, 128, 256});
    free(path);
}

void modify_shield(player_t *player, char *path)
{
    equipment_t *equipment = player->equipment;

    if (path == NULL) {
        sfSprite_destroy(equipment->shield);
        sfTexture_destroy(equipment->shield_texture);
        equipment->shield = NULL;
        equipment->shield_texture = NULL;
        free(path);
        return;
    }
    if (equipment->shield != NULL) {
        sfSprite_destroy(equipment->shield);
        sfTexture_destroy(equipment->shield_texture);
    }
    equipment->shield = sfSprite_create();
    equipment->shield_texture = sfTexture_createFromFile(path, &(sfIntRect)
    {0, 0, 128, 256});
    free(path);
}
