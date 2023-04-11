/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** spells.h
*/

#pragma once

#include "combat_scene.h"

#define PI 3.1415

typedef struct card_s {
    player_t *player;
    sfVector2f pos;
    sfVertexArray *array;
    char *name;
    int range;
    int damage;
    struct card_s *next;
} card_t;

typedef struct hand_s {
    player_t *player;
    card_t *cards;
    int nb_cards;
} hand_t;

card_t *create_card(char *name, int damage, int range, player_t *player);
void draw_card(card_t *card, sfRenderWindow *window);
void rotate_card(card_t *card, float angle);
void add_card_to_hand(hand_t *hand, char *name, int damage, int range);
hand_t *create_hand(int nb_cards, player_t *player);
void draw_hand(hand_t *hand, sfRenderWindow *window);
void update_hand(hand_t *hand);
void move_card(card_t *card, sfVector2f increment);
void create_card_vertex(card_t *card, sfVector2f pos);
