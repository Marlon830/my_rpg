/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** change_tiles.c
*/

#include "attack_mode.h"

void change_tiles(combat_map_t *map, sfVector2f new_size)
{
    int j = 0;
    int tileSize = new_size.x + 10;
    for (float x = 0; x < map->width; x++) {
        for (float y = map->height - 1; y >= 0; y--) {
            sfVector2f pos = (sfVector2f){(x * tileSize + y * tileSize)
            / 2 + map->pos.x, (x * tileSize - y * tileSize) /
            (2 * (new_size.x / new_size.y)) + map->pos.y};
            free(map->tiles[j]);
            map->tiles[j] = create_tile(pos, sfWhite, new_size, 0);
            j++;
        }
    }
}
