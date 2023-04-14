/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** update_tiles_close.c
*/

#include "attack_mode.h"

tile_t **update_tiles_close(combat_player_t *player, combat_map_t *map,
tile_t *tile, int dist)
{
    free(player->tiles_close);
    return get_tiles_close(map, tile, dist, player);
}
