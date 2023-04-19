/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** get_tiles_close.c
*/

#include "attack_mode.h"

void set_close_tiles(tile_t **tiles, tile_t *pos, int b, int len)
{
    int i = 0;

    if (b) {
        while (tiles[i] != NULL && i < len)
            i++;
        if (i < len)
            tiles[i] = pos;
    }
}

void is_good_height(tile_t *tile1, tile_t *tile2,
sfVector2f *pos, battle_scene_t *scene)
{
    if (fabs(tile1->height - tile2->height) > 5 || (scene != NULL &&
    is_there_an_enemy(tile2, scene->enemies, scene->nb_enemies))) {
        pos->x = -100;
        pos->y = -100;
    }
}

int count_nb_tiles(battle_scene_t *scene, combat_map_t *map,
tile_t *tile, int dist)
{
    sfVector2f pos = (sfVector2f){(tile->ind - (tile->ind % map->height)) /
    map->height, tile->ind % map->height};
    sfVector2f p2;
    int k = 0;
    for (int x = MAX(pos.x - dist, 0);
    x <= pos.x + dist && x < map->width; x++) {
        for (int y = MAX(pos.y - dist, 0);
        y <= pos.y + dist && y < map->height; y++) {
            p2 = (sfVector2f){x, y};
            is_good_height(tile, map->tiles[x * map->height + y], &p2, scene);
            k += (p2.x != -100 && manhattan_dist(pos, p2) <= dist);
        }
    }
    return k;
}

tile_t **get_tiles_close(battle_scene_t *scene, tile_t *tile, int dist,
combat_player_t *player)
{
    combat_map_t *map = scene->map;
    player->nb_tiles_close = count_nb_tiles(scene, map, tile, dist);
    tile_t **res = malloc(sizeof(tile_t *) * player->nb_tiles_close);
    for (int i = 0; i < player->nb_tiles_close; i++)
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
            manhattan_dist(pos, p2) <= dist, player->nb_tiles_close);
        }
    }
    return res;
}

tile_t **get_tiles_attack(battle_scene_t *scene, tile_t *tile, int dist,
combat_player_t *player)
{
    combat_map_t *map = scene->map;
    player->nb_attack_tiles = count_nb_tiles(scene, map, tile, dist);
    tile_t **res = malloc(sizeof(tile_t *) * (player->nb_attack_tiles + 1));
    for (int i = 0; i <= player->nb_attack_tiles; i++)
        res[i] = NULL;
    sfVector2f pos = (sfVector2f){(tile->ind - (tile->ind % map->height)) /
    map->height, tile->ind % map->height};
    sfVector2f p2;
    for (int x = MAX(pos.x - dist, 0); x <= pos.x + dist && x < map->width;
    x++) {
        for (int y = MAX(pos.y - dist, 0);
        y <= pos.y + dist && y < map->height; y++) {
            p2 = (sfVector2f){x, y};
            is_good_height(tile, map->tiles[x * map->height + y], &p2, NULL);
            set_close_tiles(res, map->tiles[x * map->height + y],
            manhattan_dist(pos, p2) <= dist, player->nb_attack_tiles);
        }
    }
    return res;
}
