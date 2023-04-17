/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-marlon.pegahi
** File description:
** change_all_height.c
*/

#include "attack_mode.h"

void breathing_map(combat_map_t *map, float height)
{
    for (int x = 0; x < map->width; x++) {
        for (int y = 0; y < map->height; y++) {
            change_height((cos(height) * 20) + 1
            * 50, map->tiles[x * map->height + y]);
        }
    }
}

void random_map(combat_map_t *map)
{
    int i = 0;
    float dist;
    for (int x = 0; x < map->width; x++) {
        for (int y = 0; y < map->height; y++) {
            dist = manhattan_dist(map->tiles[i]->pos, map->mousePos);
            change_height((dist <= 20 ? 10 : 0) +
            map->tiles[i]->height, map->tiles[i]);
            i++;
        }
    }
}

void test_map(combat_map_t *map, float height)
{
    sfVector2f center = map->tiles[(int)(map->width / 2) *
    map->height + (int)(map->height / 2)]->pos;
    int i = 0;
    float dist;
    for (int x = 0; x < map->width; x++) {
        for (int y = 0; y < map->height; y++) {
            dist = manhattan_dist(map->tiles[i]->pos, center);
            change_height((cos(height * 2) + 1)
            * 20 * exp(.001 * dist), map->tiles[i]);
            i++;
        }
    }
}

void water_drop_map(combat_map_t *map)
{
    int i = 0;
    for (int x = 0; x < map->width; x++) {
        for (int y = 0; y < map->height; y++) {
            float dist = manhattan_dist(map->tiles[i]->pos, map->mousePos);
            change_height((cos(1) + 2) * 20 * exp(-.001 * dist), map->tiles[i]);
            i++;
        }
    }
}

void wave_map(combat_map_t *map, float height)
{
    int i = 0;
    float dist = 0;
    for (int x = 0; x < map->width; x++) {
        for (int y = 0; y < map->height; y++) {
            dist = manhattan_dist(map->tiles[i]->pos, map->mousePos);
            change_height((cos(((float)x / 2. + y + height * 10) / 2) + 2)
            * 10 * exp(-.001 * dist), map->tiles[x * map->height + y]);
            map->tiles[x * map->height + y]->color = (sfColor){0 +
            (int)(map->tiles[x * map->height + y]->height) * 5 % 255, 50 +
            (int)(map->tiles[x * map->height + y]->height) * 5 % 255, 100 +
            (int)(map->tiles[x * map->height + y]->height) * 5 % 255, 255};
            update_tile(map->tiles[x * map->height + y]);
            i++;
        }
    }
}
