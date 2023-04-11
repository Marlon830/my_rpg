/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** color_tiles.c
*/

#include "attack_mode.h"

void color_tiles(map_t *map, player_t *player)
{
    for (int i = 0; i < map->width * map->height; i++) {
        map->tiles[i]->color = sfWhite;
        update_tile(map->tiles[i]);
    }
    map->hovered_tile->color = sfRed;
    update_tile(map->hovered_tile);
    for (int i = 0; i < player->nb_tiles_close; i++) {
            player->tiles_close[i]->color = sfGreen;
            update_tile(player->tiles_close[i]);
        }
}
