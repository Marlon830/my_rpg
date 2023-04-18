/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_attack_tiles.c
*/

#include "attack_mode.h"

tile_t **update_attack_tiles(combat_player_t *player,
card_t *card, battle_scene_t *scene)
{
    if (player->attack_tiles)
        free(player->attack_tiles);
    return get_tiles_attack(scene, player->actual_tile, card->range, player);
}
