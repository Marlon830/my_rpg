/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** create_battle_scene.c
*/

#include "attack_mode.h"

battle_scene_t *create_battle_scene(int width, int height, sfVector2f pos,
sfVector2f tile_size)
{
    battle_scene_t *res = malloc(sizeof(battle_scene_t));
    map_t *map = create_map(width, height, pos, tile_size);
    player_t *player = create_player(map->tiles[0]);
    player->tiles_close = get_tiles_close(map, player->actual_tile,
    player->actual_stats->move_points, player);
    res->map = map;
    res->player = player;
    return res;
}
