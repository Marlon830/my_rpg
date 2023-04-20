/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_enemy.c
*/

#include "attack_mode.h"

void draw_enemy(enemy_t *enemy, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, enemy->sprite->sprite, NULL);
    if (enemy->damage_taken->show)
        sfRenderWindow_drawText(window, enemy->damage_taken->text, NULL);
}
