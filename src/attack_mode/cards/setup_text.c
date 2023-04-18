/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** setup_text.c
*/

#include "attack_mode.h"

sfText *setup_text(char *text, sfVector2f pos, int police_size)
{
    sfText *res = sfText_create();
    sfText_setColor(res, sfWhite);
    sfText_setOutlineThickness(res, police_size);
    sfText_setOutlineColor(res, sfBlack);
    sfFont *font = sfFont_createFromFile("assets/font/AldotheApache.ttf");
    sfText_setFont(res, font);
    sfText_setPosition(res, pos);
    sfText_setString(res, text);
    return res;
}
