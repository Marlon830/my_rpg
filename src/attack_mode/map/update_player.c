/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** update_player.c
*/

#include "attack_mode.h"

void update_player_overlay(combat_player_t *player)
{
    char *hp = my_strcat("hp ", int_to_str(player->actual_stats->health_point));
    char *energy = my_strcat("energy ",
    int_to_str(player->actual_stats->energy_points));
    char *move_points = my_strcat("move ",
    int_to_str(player->actual_stats->move_points));
    update_combat_text(hp, player->overlay[0]->text);
    update_combat_text(energy, player->overlay[1]->text);
    update_combat_text(move_points, player->overlay[2]->text);
    free(hp);
    free(move_points);
    free(energy);
}

void update_combat_equipment3(combat_player_t *player, equipment_t *equip)
{
    if (equip->sword != NULL) {
        sfSprite_setTexture(equip->sword, equip->sword_texture, sfTrue);
        sfSprite_setTextureRect(equip->sword, (sfIntRect)
        {0, 0, 32, 32});
        sfSprite_setPosition(equip->sword, player->actual_tile->pos);
    }
    if (equip->shield != NULL) {
        sfSprite_setTexture(equip->shield, equip->shield_texture, sfTrue);
        sfSprite_setTextureRect(equip->shield, (sfIntRect)
        {0, 0, 32, 32});
        sfSprite_setPosition(equip->shield, player->actual_tile->pos);
    }
}

void update_combat_equipment2(combat_player_t *player, equipment_t *equip)
{
    if (equip->boots != NULL) {
        sfSprite_setTexture(equip->boots, equip->boots_texture, sfTrue);
        sfSprite_setTextureRect(equip->boots, (sfIntRect)
        {0, 0, 32, 32});
        sfSprite_setPosition(equip->boots, player->actual_tile->pos);
    }
    if (equip->amulet != NULL) {
        sfSprite_setTexture(equip->amulet, equip->amulet_texture, sfTrue);
        sfSprite_setTextureRect(equip->amulet, (sfIntRect)
        {0, 0, 32, 32});
        sfSprite_setPosition(equip->amulet, player->actual_tile->pos);
    }
    if (equip->ring != NULL) {
        sfSprite_setTexture(equip->ring, equip->ring_texture, sfTrue);
        sfSprite_setTextureRect(equip->ring, (sfIntRect)
        {0, 0, 32, 32});
        sfSprite_setPosition(equip->ring, player->actual_tile->pos);
    }
    update_combat_equipment3(player, equip);
}

void update_combat_equipment(combat_player_t *player, equipment_t *equip)
{
    if (equip->helmet != NULL) {
        sfSprite_setTexture(equip->helmet, equip->helmet_texture, sfTrue);
        sfSprite_setTextureRect(equip->helmet, (sfIntRect)
        {0, 0, 32, 32});
        sfSprite_setPosition(equip->helmet, player->actual_tile->pos);
    }
    if (equip->armor != NULL) {
        sfSprite_setTexture(equip->armor, equip->armor_texture, sfTrue);
        sfSprite_setTextureRect(equip->armor, (sfIntRect)
        {0, 0, 32, 32});
        sfSprite_setPosition(equip->armor, player->actual_tile->pos);
    }
    if (equip->pants != NULL) {
        sfSprite_setTexture(equip->pants, equip->pants_texture, sfTrue);
        sfSprite_setTextureRect(equip->pants, (sfIntRect)
        {0, 0, 32, 32});
        sfSprite_setPosition(equip->pants, player->actual_tile->pos);
    }
    update_combat_equipment2(player, equip);
}

void update_player(combat_player_t *player, battle_scene_t *scene)
{
    sfVertexArray_clear(player->array_character);
    set_player_pos(player);
    if (player->actual_stats->energy_points < 0)
        player->actual_stats->energy_points = 0;
    update_player_overlay(player);
    update_damage_taken(player->damage_taken);
    if (player->actual_stats->health_point <= 0 &&
    !player->damage_taken->show && scene->win != -3) {
        scene->win = -2;
    }
    sfSprite_setPosition(player->sprite->sprite, player->actual_tile->pos);
    update_combat_equipment(player, player->equipment);
}
