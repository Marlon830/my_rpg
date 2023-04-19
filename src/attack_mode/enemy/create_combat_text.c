/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_combat_text.c
*/

#include "attack_mode.h"

combat_text_t *create_combat_text(sfVector2f char_pos)
{
    sfVector2f pos = (sfVector2f){char_pos.x - 25, char_pos.y - 80};
    combat_text_t *res = malloc(sizeof(combat_text_t) * 2);
    res->text = sfText_create();
    sfText_setColor(res->text, sfWhite);
    sfText_setOutlineThickness(res->text, 2);
    sfText_setOutlineColor(res->text, sfBlack);
    sfFont *font = sfFont_createFromFile("assets/font/AldotheApache.ttf");
    sfText_setFont(res->text, font);
    sfText_setPosition(res->text, pos);
    sfText_setString(res->text, "test");
    res->clock = sfClock_create();
    res->show = 0;
    return res;
}
