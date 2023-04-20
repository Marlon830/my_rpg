/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_random_enemies.c
*/

#include "attack_mode.h"

enemy_t **create_random_enemies(combat_map_t *map, int nb_enemy)
{
    int x;
    int y;
    unsigned int nb = 10;
    unsigned int ans = (size_t) &nb;
    enemy_t **res = malloc(sizeof(enemy_t *) * nb_enemy);

    srand(ans);
    for (int i = 0; i < nb_enemy; i++) {
        x = rand() % map->width + 1;
        y = rand() % map->height + 1;
        res[i] = create_enemy(map->tiles[x * map->height + y], "df");
    }
    return res;
}
