/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_combat_text.c
*/

#include "attack_mode.h"

void destroy_combat_text(combat_text_t *text)
{
    sfClock_destroy(text->clock);
    sfText_destroy(text->text);
}
