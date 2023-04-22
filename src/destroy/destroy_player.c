/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_player.c
*/

#include "project.h"

void destroy_equipment2(equipment_t *equipment)
{
    if (equipment->amulet != NULL)
        sfSprite_destroy(equipment->amulet);
    if (equipment->amulet_texture != NULL)
        sfTexture_destroy(equipment->amulet_texture);
    if (equipment->ring != NULL)
        sfSprite_destroy(equipment->ring);
    if (equipment->ring_texture != NULL)
        sfTexture_destroy(equipment->ring_texture);
    if (equipment->sword != NULL)
        sfSprite_destroy(equipment->sword);
    if (equipment->sword_texture != NULL)
        sfTexture_destroy(equipment->sword_texture);
    if (equipment->shield != NULL)
        sfSprite_destroy(equipment->shield);
    if (equipment->shield_texture != NULL)
        sfTexture_destroy(equipment->shield_texture);
    free(equipment);
}

void destroy_equipment(equipment_t *equipment)
{
    if (equipment->helmet != NULL)
        sfSprite_destroy(equipment->helmet);
    if (equipment->helmet_texture != NULL)
        sfTexture_destroy(equipment->helmet_texture);
    if (equipment->armor != NULL)
        sfSprite_destroy(equipment->armor);
    if (equipment->armor_texture != NULL)
        sfTexture_destroy(equipment->armor_texture);
    if (equipment->pants != NULL)
        sfSprite_destroy(equipment->pants);
    if (equipment->pants_texture != NULL)
        sfTexture_destroy(equipment->pants_texture);
    if (equipment->boots != NULL)
        sfSprite_destroy(equipment->boots);
    if (equipment->boots_texture != NULL)
        sfTexture_destroy(equipment->boots_texture);
    destroy_equipment2(equipment);
}

void destroy_player_game(player_t *player)
{
    if (player == NULL)
        return;
    if (player->equipment != NULL)
        destroy_equipment(player->equipment);
    if (player->character != NULL)
        destroy_image(player->character);
    if (player->player_stats != NULL)
        destroy_stats(player->player_stats);
    free(player);
}
