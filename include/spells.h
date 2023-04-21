/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** spells.h
*/

#pragma once

#include "attack_structs.h"

#define PI 3.1415

card_t *create_card(char *name, int damage, int range,
combat_player_t *player);
void draw_card(card_t *card, sfRenderWindow *window);
void rotate_card(card_t *card, float angle);
void add_card_to_hand(hand_t *hand, char *name, int damage, int range);
hand_t *create_hand(int nb_cards, combat_player_t *player);
void draw_hand(hand_t *hand, sfRenderWindow *window);
void update_hand(hand_t *hand, sfVector2f mouse_pos);
void move_card(card_t *card, sfVector2f increment);
void create_card_vertex(card_t *card, sfVector2f pos);
void click_card(sfRenderWindow *window, sfEvent event, hand_t *hand);
tile_t **update_attack_tiles(combat_player_t *player,
card_t *card, battle_scene_t *scene);
