/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_enemy_tiles_close.c
*/

#include "attack_mode.h"

tile_t **get_enemy_tiles_close(battle_scene_t *scene, tile_t *tile, int dist,
enemy_t *enemy)
{
    combat_map_t *map = scene->map;
    enemy->nb_tiles_close = count_nb_tiles(scene, map, tile, dist);
    tile_t **res = malloc(sizeof(tile_t *) * enemy->nb_tiles_close);
    for (int i = 0; i < enemy->nb_tiles_close; i++)
        res[i] = NULL;
    sfVector2f pos = (sfVector2f){(tile->ind - (tile->ind % map->height)) /
    map->height, tile->ind % map->height};
    for (int x = MAX(pos.x - dist, 0); x <= pos.x + dist && x < map->width;
    x++) {
        for (int y = MAX(pos.y - dist, 0);
        y <= pos.y + dist && y < map->height; y++) {
            sfVector2f p2 = (sfVector2f){x, y};
            is_good_height(tile, map->tiles[x * map->height + y], &p2, scene);
            set_close_tiles(res, map->tiles[x * map->height + y],
            manhattan_dist(pos, p2) <= dist, enemy->nb_tiles_close);
        }
    }
    return res;
}
