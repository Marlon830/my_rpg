/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_manager.c
*/

#include "project.h"

void modify_helmet(player_t *player, char *path)
{
    equipment_t *equipment = player->equipment;

    if (path == NULL) {
        sfSprite_destroy(equipment->helmet);
        sfTexture_destroy(equipment->helmet_texture);
        equipment->helmet = NULL;
        equipment->helmet_texture = NULL;
        free(path);
        return;
    }
    if (equipment->helmet != NULL) {
        sfSprite_destroy(equipment->helmet);
        sfTexture_destroy(equipment->helmet_texture);
    }
    equipment->helmet = sfSprite_create();
    equipment->helmet_texture = sfTexture_createFromFile(path, &(sfIntRect)
    {0, 0, 128, 256});
    free(path);
}

void modify_armor(player_t *player, char *path)
{
    equipment_t *equipment = player->equipment;

    if (path == NULL) {
        sfSprite_destroy(equipment->armor);
        sfTexture_destroy(equipment->armor_texture);
        equipment->armor = NULL;
        equipment->armor_texture = NULL;
        free(path);
        return;
    }
    if (equipment->armor != NULL) {
        sfSprite_destroy(equipment->armor);
        sfTexture_destroy(equipment->armor_texture);
    }
    equipment->armor = sfSprite_create();
    equipment->armor_texture = sfTexture_createFromFile(path, &(sfIntRect)
    {0, 0, 128, 256});
    free(path);
}

void modify_pants(player_t *player, char *path)
{
    equipment_t *equipment = player->equipment;

    if (path == NULL) {
        sfSprite_destroy(equipment->pants);
        sfTexture_destroy(equipment->pants_texture);
        equipment->pants = NULL;
        equipment->pants_texture = NULL;
        free(path);
        return;
    }
    if (equipment->pants != NULL) {
        sfSprite_destroy(equipment->pants);
        sfTexture_destroy(equipment->pants_texture);
    }
    equipment->pants = sfSprite_create();
    equipment->pants_texture = sfTexture_createFromFile(path, &(sfIntRect)
    {0, 0, 128, 256});
    free(path);
}

void modify_boots(player_t *player, char *path)
{
    equipment_t *equipment = player->equipment;

    if (path == NULL) {
        sfSprite_destroy(equipment->boots);
        sfTexture_destroy(equipment->boots_texture);
        equipment->boots = NULL;
        equipment->boots_texture = NULL;
        free(path);
        return;
    }
    if (equipment->boots != NULL) {
        sfSprite_destroy(equipment->boots);
        sfTexture_destroy(equipment->boots_texture);
    }
    equipment->boots = sfSprite_create();
    equipment->boots_texture = sfTexture_createFromFile(path, &(sfIntRect)
    {0, 0, 128, 256});
    free(path);
}

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
