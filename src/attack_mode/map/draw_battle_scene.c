/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** draw_battle_scene.c
*/

#include "attack_mode.h"

void draw_batle_scene(battle_scene_t *scene, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, (sfColor){20, 54, 66, 255});
    sfRenderWindow_drawVertexArray(window, scene->player->array_character,
    NULL);
    draw_map(window, scene->map);
    draw_player(scene->player, window);
    draw_hand(scene->hand, window);
    for (int i = 0; i < scene->nb_enemies; i++) {
        if (scene->enemies[i] != NULL)
            draw_enemy(scene->enemies[i], window);
    }
}
