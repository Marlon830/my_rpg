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

void set_overlay_player(combat_player_t *player)
{
    player->overlay[0] = create_combat_text((sfVector2f){100, 100});
    player->overlay[1] = create_combat_text((sfVector2f){100, 200});
    player->overlay[2] = create_combat_text((sfVector2f){100, 300});
    player->overlay[3] = create_combat_text((sfVector2f){100, 400});
    player->overlay[4] = NULL;
}

combat_player_t *create_player(tile_t *tile)
{
    combat_player_t *res = malloc(sizeof(combat_player_t));
    res->actual_tile = tile;
    res->array_character = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(res->array_character, sfQuads);
    set_player_pos(res);
    res->actual_stats = create_stats(10, 100, 3);
    res->basic_stats = create_stats(10 ,100, 3);
    res->state = MOVING;
    res->attack_tiles = NULL;
    res->card = NULL;
    res->overlay = malloc(sizeof(combat_text_t *) * 5);
    res->damage_taken = create_combat_text((sfVector2f){0, 0});
    set_overlay_player(res);
    res->sprite = create_image(res->actual_tile->pos,
    "player.png", (sfIntRect){0, 0, 32, 32},
    (sfVector2f){32, 32});
    sfSprite_setScale(res->sprite->sprite, (sfVector2f){5, 5});
    sfSprite_setOrigin(res->sprite->sprite, (sfVector2f){17, 24});
    return res;
}
