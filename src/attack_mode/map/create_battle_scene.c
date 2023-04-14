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
    combat_map_t *map = create_map(width, height, pos, tile_size);
    combat_player_t *player = create_player(map->tiles[0]);
    hand_t *hand = create_hand(1, res->player);
    player->tiles_close = get_tiles_close(map, player->actual_tile,
    player->actual_stats->move_points, player);
    res->map = map;
    res->player = player;
    res->hand = hand;
    res->hand->player = player;
    res->nb_enemies = 0;
    res->win = 0;
    res->enemies = create_enemies_from_txt
    ("combat_scene/fight01.txt", map, &res->nb_enemies);
    return res;
}
