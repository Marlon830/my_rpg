/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_black_fade.c
*/

#include "attack_mode.h"

void add_color(sfColor *color)
{
    if (color->a + 5 < 255)
        color->a += 5;
}

void update_black_fade(battle_scene_t *scene)
{
    if (scene->win == -3) {
        for (int i = 0; i < 4; i++) {
            add_color(&sfVertexArray_getVertex(scene->black_fade, i)->color);
        }
    }
}
