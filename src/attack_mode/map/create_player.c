/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** create_player.c
*/

#include "attack_mode.h"

void set_player_pos(combat_player_t *player)
{
    int size = 20;
    sfVector2f pos = player->actual_tile->pos;
    sfVector2f p1 = (sfVector2f){pos.x - size, pos.y};
    sfVector2f p2 = (sfVector2f){pos.x - size, pos.y - 2 * size};
    sfVector2f p3 = (sfVector2f){pos.x + size, pos.y - 2 * size};
    sfVector2f p4 = (sfVector2f){pos.x + size, pos.y};
    sfVertexArray_append(player->array_character, vertex_create(p1, sfBlack));
    sfVertexArray_append(player->array_character, vertex_create(p2, sfBlack));
    sfVertexArray_append(player->array_character, vertex_create(p3, sfBlack));
    sfVertexArray_append(player->array_character, vertex_create(p4, sfBlack));
}

combat_player_t *create_player(tile_t *tile)
{
    combat_player_t *res = malloc(sizeof(combat_player_t));
    res->actual_tile = tile;
    res->array_character = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(res->array_character, sfQuads);
    set_player_pos(res);
    res->actual_stats = create_stats(10, 100, 5);
    res->basic_stats = create_stats(10 ,100, 5);
    res->state = MOVING;
    res->attack_tiles = NULL;
    res->card = NULL;
    return res;
}