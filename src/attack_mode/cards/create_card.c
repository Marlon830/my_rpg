/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** create_card.c
*/

#include "attack_mode.h"

void add_border(card_t *card, sfVector2f pos)
{
    sfVector2f p1 = (sfVector2f){pos.x - 105, pos.y};
    sfVector2f p2 = (sfVector2f){pos.x + 105, pos.y};
    sfVector2f p3 = (sfVector2f){pos.x + 105, pos.y - 305};
    sfVector2f p4 = (sfVector2f){pos.x - 105, pos.y - 305};

    sfVertexArray_append(card->array, create_vertex(p1, sfRed));
    sfVertexArray_append(card->array, create_vertex(p2, sfRed));
    sfVertexArray_append(card->array, create_vertex(p3, sfRed));
    sfVertexArray_append(card->array, create_vertex(p4, sfRed));
}

void create_card_vertex(card_t *card, sfVector2f pos)
{
    add_border(card, pos);
    sfVector2f p1 = (sfVector2f){pos.x - 100, pos.y};
    sfVector2f p2 = (sfVector2f){pos.x + 100, pos.y};
    sfVector2f p3 = (sfVector2f){pos.x + 100, pos.y - 300};
    sfVector2f p4 = (sfVector2f){pos.x - 100, pos.y - 300};

    sfVertexArray_append(card->array, create_vertex(p1, sfBlack));
    sfVertexArray_append(card->array, create_vertex(p2, sfBlack));
    sfVertexArray_append(card->array, create_vertex(p3, sfBlack));
    sfVertexArray_append(card->array, create_vertex(p4, sfBlack));
    sfVertexArray_setPrimitiveType(card->array, sfQuads);
}

card_t *create_card(char *name, int damage, int range, player_t *player)
{
    card_t *res = malloc(sizeof(card_t));
    res->array = sfVertexArray_create();
    res->damage = damage;
    res->name = name;
    res->range = range;
    res->player = player;
    res->next = NULL;
    res->pos = (sfVector2f){1920 / 2, 1080};
    create_card_vertex(res, res->pos);
    return res;
}
