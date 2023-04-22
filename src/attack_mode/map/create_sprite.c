/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_sprite.c
*/

#include "attack_mode.h"

sprite_t *create_sprite(char *filename, sfVector2f pos)
{
    sprite_t *res = malloc(sizeof(sprite_t));
    res->pos = pos;
    res->sprite = sfSprite_create();
    res->texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setPosition(res->sprite, pos);
    sfSprite_setTexture(res->sprite, res->texture, sfFalse);
    return res;
}
