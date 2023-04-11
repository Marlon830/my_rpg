/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_tile.c
*/

#include "attack_mode.h"

void draw_tile(sfRenderWindow *window, tile_t *tile)
{
    sfRenderWindow_drawVertexArray(window, tile->array_tile, NULL);
    sfRenderWindow_drawVertexArray(window, tile->array_walls, NULL);

}
