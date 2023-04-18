/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** update_tiles_close.c
*/

#include "attack_mode.h"

tile_t **update_tiles_close(combat_player_t *player, battle_scene_t *scene,
tile_t *tile, int dist)
{
    free(player->tiles_close);
    return get_tiles_close(scene, tile, dist, player);
}
