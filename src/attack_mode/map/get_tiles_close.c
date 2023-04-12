/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** get_tiles_close.c
*/

#include "attack_mode.h"

void set_close_tiles(tile_t **tiles, tile_t *pos, int manhattan, int dist)
{
    int i = 0;
    if (manhattan <= dist) {
        while (tiles[i] != NULL)
            i++;
        tiles[i] = pos;
    }
}

void is_good_height(tile_t *tile1, tile_t *tile2, sfVector2f *pos)
{
    if (abs(tile1->height - tile2->height) > 5) {
        pos->x = -100;
        pos->y = -100;
    }
}

int count_nb_tiles(map_t *map, tile_t *tile, int dist)
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
            is_good_height(tile, map->tiles[x * map->height + y], &p2);
            k += (p2.x != -100 && manhattan_dist(pos, p2) <= dist);
        }
    }
    return k;
}

tile_t **get_tiles_close(map_t *map, tile_t *tile, int dist, player_t *player)
{
    player->nb_tiles_close = count_nb_tiles(map, tile, dist);
    tile_t **res = malloc(sizeof(tile_t *) * player->nb_tiles_close);
    for (int i = 0; i < player->nb_tiles_close; i++)
        res[i] = NULL;
    sfVector2f pos = (sfVector2f){(tile->ind - (tile->ind % map->height)) /
    map->height, tile->ind % map->height};
    sfVector2f p2;
    for (int x = pos.x - dist;
    x <= pos.x + dist && x < map->width; x++) {
        if (x < 0)
            continue;
        for (int y = MAX(pos.y - dist, 0);
        y <= pos.y + dist && y < map->height; y++) {
            p2 = (sfVector2f){x, y};
            is_good_height(tile, map->tiles[x * map->height + y], &p2);
            set_close_tiles(res, map->tiles[x * map->height + y],
            manhattan_dist(pos, p2), dist);
        }
    }
    return res;
}

tile_t **get_tiles_attack(map_t *map, tile_t *tile, int dist, player_t *player)
{
    player->nb_attack_tiles = count_nb_tiles(map, tile, dist);
    tile_t **res = malloc(sizeof(tile_t *) * player->nb_attack_tiles);
    for (int i = 0; i < player->nb_attack_tiles; i++)
        res[i] = NULL;
    sfVector2f pos = (sfVector2f){(tile->ind - (tile->ind % map->height)) /
    map->height, tile->ind % map->height};
    sfVector2f p2;
    for (int x = pos.x - dist;
    x <= pos.x + dist && x < map->width; x++) {
        if (x < 0)
            continue;
        for (int y = MAX(pos.y - dist, 0);
        y <= pos.y + dist && y < map->height; y++) {
            p2 = (sfVector2f){x, y};
            is_good_height(tile, map->tiles[x * map->height + y], &p2);
            set_close_tiles(res, map->tiles[x * map->height + y],
            manhattan_dist(pos, p2), dist);
        }
    }
    return res;
}
