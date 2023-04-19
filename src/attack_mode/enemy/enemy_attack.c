/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** enemy_attack.c
*/

#include "attack_mode.h"

sfVector2f get_pos_in_tiles(combat_map_t *map, int i, tile_t **tiles)
{
    int tile_y = tiles[i]->ind % map->height;
    int tile_x = (tiles[i]->ind - tile_y) / map->height;
    return (sfVector2f){tile_x, tile_y};
}

tile_t *get_closest_tile(sfVector2f pos, combat_map_t *map,
enemy_t *enemy, sfVector2f player_pos)
{
    int i = 0;
    int min = manhattan_dist(player_pos, pos);
    int ind_res = enemy->actual_tile->ind;
    tile_t **tiles = enemy->tiles_close;
    sfVector2f tile_pos;
    while (i < enemy->nb_tiles_close) {
        tile_pos = get_pos_in_tiles(map, i, tiles);
        if (manhattan_dist(player_pos, tile_pos) < min &&
        manhattan_dist(tile_pos, player_pos) >= enemy->range) {
            min = manhattan_dist(player_pos, tile_pos);
            ind_res = i;
        }
        i++;
    }
    if (ind_res != enemy->actual_tile->ind) {
        enemy->actual_stats->move_points -=
        manhattan_dist(get_pos_in_tiles(map, ind_res, tiles), pos);
        return tiles[ind_res];
    }
    return enemy->actual_tile;
}

void enemy_get_close(enemy_t *enemy, battle_scene_t *scene)
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

void enemy_attack(enemy_t *enemy, battle_scene_t *scene)
{
    if (enemy != NULL)
    enemy_get_close(enemy, scene);
}
