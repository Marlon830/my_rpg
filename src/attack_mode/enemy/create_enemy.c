/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_enemy.c
*/

#include "attack_mode.h"

void set_enemy_pos(enemy_t *enemy)
{
    int size = 20;
    sfVector2f pos = enemy->actual_tile->pos;
    sfVector2f p1 = (sfVector2f){pos.x - size, pos.y};
    sfVector2f p2 = (sfVector2f){pos.x - size, pos.y - 2 * size};
    sfVector2f p3 = (sfVector2f){pos.x + size, pos.y - 2 * size};
    sfVector2f p4 = (sfVector2f){pos.x + size, pos.y};
    sfVertexArray_append(enemy->array_character, vertex_create(p1, sfRed));
    sfVertexArray_append(enemy->array_character, vertex_create(p2, sfRed));
    sfVertexArray_append(enemy->array_character, vertex_create(p3, sfRed));
    sfVertexArray_append(enemy->array_character, vertex_create(p4, sfRed));
}

enemy_t *create_enemy(tile_t *tile)
{
    enemy_t *res = malloc(sizeof(enemy_t));
    res->actual_tile = tile;
    res->array_character = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(res->array_character, sfQuads);
    set_enemy_pos(res);
    res->actual_stats = create_stats(5, 100, 5);
    res->basic_stats = create_stats(5, 100, 5);
    res->range = 5;
    res->attack_tiles = NULL;
    res->damage_taken = create_combat_text(res->actual_tile->pos);
    return res;
}