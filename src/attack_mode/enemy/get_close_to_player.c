/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_close_to_player.c
*/

#include "attack_mode.h"



tile_t *get_closest_tile(sfVector2f pos, combat_map_t *map,
enemy_t *enemy, sfVector2f player_pos)
{
    int i = 0;
    int min = manhattan_dist(player_pos, pos);
    int ind_res = enemy->actual_tile->ind;
    tile_t **tiles = enemy->tiles_close;
    sfVector2f tile_pos;
    while (i < enemy->nb_tiles_close) {
        tile_pos = get_pos_in_tiles(map, tiles[i]);
        if (manhattan_dist(player_pos, tile_pos) < min &&
        manhattan_dist(tile_pos, player_pos) >= enemy->range) {
            min = manhattan_dist(player_pos, tile_pos);
            ind_res = i;
        }
        i++;
    }
    if (ind_res != enemy->actual_tile->ind) {
        enemy->actual_stats->move_points -=
        manhattan_dist(get_pos_in_tiles(map, tiles[ind_res]), pos);
        return tiles[ind_res];
    }
    return enemy->actual_tile;
}

void enemy_get_close_to_player(enemy_t *enemy, battle_scene_t *scene)
{
    combat_player_t *player = scene->player;
    combat_map_t *map = scene->map;
    int player_y = player->actual_tile->ind % map->height;
    int player_x = (player->actual_tile->ind - player_y) / map->height;
    int y = enemy->actual_tile->ind % map->height;
    int x = (enemy->actual_tile->ind - y) / map->height;
    sfVector2f player_pos = (sfVector2f){player_x, player_y};
    sfVector2f pos = (sfVector2f){x, y};
    enemy->actual_tile = get_closest_tile(pos, map, enemy, player_pos);
}
