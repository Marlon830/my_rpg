/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_attack_tiles.c
*/

#include "attack_mode.h"

tile_t **update_attack_tiles(combat_map_t *map, combat_player_t *player,
card_t *card)
{
    if (player->attack_tiles)
        free(player->attack_tiles);
    return get_tiles_attack(map, player->actual_tile, card->range, player);
}
