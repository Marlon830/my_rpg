/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** create_card.c
*/

#include "attack_mode.h"

void add_border(card_t *card, sfVector2f pos)
{
    sfVector2f p1 = (sfVector2f){pos.x - 105, pos.y + 5};
    sfVector2f p2 = (sfVector2f){pos.x + 105, pos.y + 5};
    sfVector2f p3 = (sfVector2f){pos.x + 105, pos.y - 305};
    sfVector2f p4 = (sfVector2f){pos.x - 105, pos.y - 305};

    sfVertexArray_append(card->array, vertex_create(p1, sfRed));
    sfVertexArray_append(card->array, vertex_create(p2, sfRed));
    sfVertexArray_append(card->array, vertex_create(p3, sfRed));
    sfVertexArray_append(card->array, vertex_create(p4, sfRed));
}

void create_card_vertex(card_t *card, sfVector2f pos)
{
    sfVertexArray_clear(card->array);
    add_border(card, pos);
    sfVector2f p1 = (sfVector2f){pos.x - 100, pos.y};
    sfVector2f p2 = (sfVector2f){pos.x + 100, pos.y};
    sfVector2f p3 = (sfVector2f){pos.x + 100, pos.y - 300};
    sfVector2f p4 = (sfVector2f){pos.x - 100, pos.y - 300};

    sfVertexArray_append(card->array, vertex_create(p1, sfBlack));
    sfVertexArray_append(card->array, vertex_create(p2, sfBlack));
    sfVertexArray_append(card->array, vertex_create(p3, sfBlack));
    sfVertexArray_append(card->array, vertex_create(p4, sfBlack));
    sfVertexArray_setPrimitiveType(card->array, sfQuads);
    update_card_overlay(card->overlay, card);
}

card_t *create_card(char *name, int damage, int range, combat_player_t *player)
{
    card_t *res = malloc(sizeof(card_t));
    res->array = sfVertexArray_create();
    res->damage = damage;
    res->name = name;
    res->range = range;
    res->player = player;
    res->next = NULL;
    res->previous = NULL;
    res->state = NOTHING;
    res->angle = 0;
    res->energy = 5;
    res->pos = (sfVector2f){1920 / 2, 1080};
    res->overlay = create_card_overlay(res);
    create_card_vertex(res, res->pos);
    res->energy = 5;
    return res;
}
