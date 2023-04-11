/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** draw_battle_scene.c
*/

#include "attack_mode.h"

void draw_batle_scene(battle_scene_t *scene, sfRenderWindow *window)
{
    draw_map(window, scene->map);
    draw_player(scene->player, window);
    draw_hand(scene->hand, window);
}
