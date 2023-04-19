/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_manager3.c
*/

#include "project.h"

void draw_equipment4(project_t *project, player_t *player)
{
    equipment_t *equip = player->equipment;

    if (equip->sword != NULL) {
        sfSprite_setTexture(equip->sword, equip->sword_texture, sfTrue);
        sfSprite_setTextureRect(equip->sword, (sfIntRect)
        {player->character->sprite_pos.x, player->character->sprite_pos.y,
        player->character->sprite_size.x, player->character->sprite_size.y});
        sfSprite_setPosition(equip->sword, player->character->pos);
        if (!project->inventory->is_active)
            sfRenderWindow_drawSprite(WINDOW, equip->sword, NULL);
    }
    if (equip->shield != NULL) {
        sfSprite_setTexture(equip->shield, equip->shield_texture, sfTrue);
        sfSprite_setTextureRect(equip->shield, (sfIntRect)
        {player->character->sprite_pos.x, player->character->sprite_pos.y,
        player->character->sprite_size.x, player->character->sprite_size.y});
        sfSprite_setPosition(equip->shield, player->character->pos);
        if (!project->inventory->is_active)
            sfRenderWindow_drawSprite(WINDOW, equip->shield, NULL);
    }
}

void draw_equipment3(project_t *project, player_t *player)
{
    equipment_t *equip = player->equipment;
    if (equip->amulet != NULL) {
        sfSprite_setTexture(equip->amulet, equip->amulet_texture, sfTrue);
        sfSprite_setTextureRect(equip->amulet, (sfIntRect)
        {player->character->sprite_pos.x, player->character->sprite_pos.y,
        player->character->sprite_size.x, player->character->sprite_size.y});
        sfSprite_setPosition(equip->amulet, player->character->pos);
        if (!project->inventory->is_active)
            sfRenderWindow_drawSprite(WINDOW, equip->amulet, NULL);
    }
    if (equip->ring != NULL) {
        sfSprite_setTexture(equip->ring, equip->ring_texture, sfTrue);
        sfSprite_setTextureRect(equip->ring, (sfIntRect)
        {player->character->sprite_pos.x, player->character->sprite_pos.y,
        player->character->sprite_size.x, player->character->sprite_size.y});
        sfSprite_setPosition(equip->ring, player->character->pos);
        if (!project->inventory->is_active)
            sfRenderWindow_drawSprite(WINDOW, equip->ring, NULL);
    }
    draw_equipment4(project, player);
}

void draw_equipment2(project_t *project, player_t *player)
{
    equipment_t *equip = player->equipment;
    if (equip->pants != NULL) {
        sfSprite_setTexture(equip->pants, equip->pants_texture, sfTrue);
        sfSprite_setTextureRect(equip->pants, (sfIntRect)
        {player->character->sprite_pos.x, player->character->sprite_pos.y,
        player->character->sprite_size.x, player->character->sprite_size.y});
        sfSprite_setPosition(equip->pants, player->character->pos);
        if (!project->inventory->is_active)
            sfRenderWindow_drawSprite(WINDOW, equip->pants, NULL);
    }
    if (equip->boots != NULL) {
        sfSprite_setTexture(equip->boots, equip->boots_texture, sfTrue);
        sfSprite_setTextureRect(equip->boots, (sfIntRect)
        {player->character->sprite_pos.x, player->character->sprite_pos.y,
        player->character->sprite_size.x, player->character->sprite_size.y});
        sfSprite_setPosition(equip->boots, player->character->pos);
        if (!project->inventory->is_active)
            sfRenderWindow_drawSprite(WINDOW, equip->boots, NULL);
    }
    draw_equipment3(project, player);
}

void draw_equipment(project_t *project, player_t *player)
{
    equipment_t *equip = player->equipment;
    if (equip->helmet != NULL) {
        sfSprite_setTexture(equip->helmet, equip->helmet_texture, sfTrue);
        sfSprite_setTextureRect(equip->helmet, (sfIntRect)
        {player->character->sprite_pos.x, player->character->sprite_pos.y,
        player->character->sprite_size.x, player->character->sprite_size.y});
        sfSprite_setPosition(equip->helmet, player->character->pos);
        if (!project->inventory->is_active)
            sfRenderWindow_drawSprite(WINDOW, equip->helmet, NULL);
    }
    if (equip->armor != NULL) {
        sfSprite_setTexture(equip->armor, equip->armor_texture, sfTrue);
        sfSprite_setTextureRect(equip->armor, (sfIntRect)
        {player->character->sprite_pos.x, player->character->sprite_pos.y,
        player->character->sprite_size.x, player->character->sprite_size.y});
        sfSprite_setPosition(equip->armor, player->character->pos);
        if (!project->inventory->is_active)
            sfRenderWindow_drawSprite(WINDOW, equip->armor, NULL);
    }
    draw_equipment2(project, player);
}
