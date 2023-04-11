/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** move_player.c
*/

#include "attack_mode.h"

void move_player(player_t *player, tile_t *tile, map_t *map)
{
    sfVector2f pos = (sfVector2f){(tile->ind - (tile->ind % map->height))
    / map->height, tile->ind % map->height};
    sfVector2f pos2 = (sfVector2f){(player->actual_tile->ind -
    (player->actual_tile->ind % map->height))
    / map->height, player->actual_tile->ind % map->height};
    for (int i = 0; i < player->nb_tiles_close; i++) {
        if (player->tiles_close[i]->ind == tile->ind) {
            player->actual_stats->move_points -= manhattan_dist(pos2, pos);
            player->actual_tile = tile;
            return;
        }
    }
}
