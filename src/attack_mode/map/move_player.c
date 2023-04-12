/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** move_player.c
*/

#include "attack_mode.h"

void attack_player(player_t *player, tile_t *tile, map_t *map)
{
    if (!(player->state == ATTACKING && player->card))
        return;
    for (int i = 0; i < player->nb_attack_tiles; i++) {
        if (player->attack_tiles[i]->ind == tile->ind) {
            free(player->card);
            player->state = MOVING;
            player->card = NULL;
            return;
        }
    }
}

void move_player(player_t *player, tile_t *tile, map_t *map)
{
    if (player->state != MOVING) {
        attack_player(player, tile, map);
        return;
    }
    if (tile->ind == -1)
        return;
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
