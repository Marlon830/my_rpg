/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** draw_player.c
*/

#include "attack_mode.h"

void draw_combat_equipment(sfRenderWindow *window, equipment_t *equip)
{
    if (equip->helmet != NULL)
        sfRenderWindow_drawSprite(window, equip->helmet, NULL);
    if (equip->armor != NULL)
        sfRenderWindow_drawSprite(window, equip->armor, NULL);
    if (equip->pants != NULL)
        sfRenderWindow_drawSprite(window, equip->pants, NULL);
    if (equip->boots != NULL)
        sfRenderWindow_drawSprite(window, equip->boots, NULL);
    if (equip->amulet != NULL)
        sfRenderWindow_drawSprite(window, equip->amulet, NULL);
    if (equip->ring != NULL)
        sfRenderWindow_drawSprite(window, equip->ring, NULL);
    if (equip->sword != NULL)
        sfRenderWindow_drawSprite(window, equip->sword, NULL);
    if (equip->shield != NULL)
        sfRenderWindow_drawSprite(window, equip->shield, NULL);
}

void draw_player(combat_player_t *player, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, player->sprite->sprite, NULL);
    draw_combat_equipment(window, player->equipment);
    if (player->damage_taken->show)
        sfRenderWindow_drawText(window, player->damage_taken->text, NULL);
}
