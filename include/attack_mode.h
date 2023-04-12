/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** combat_scene.h
*/

#pragma once


#include "attack_structs.h"
#include "combat_scene.h"
#include "spells.h"

void analyse_events(sfRenderWindow *window, sfEvent event,
battle_scene_t *scene, hand_t *hand);
battle_scene_t *create_battle_scene(int width, int height, sfVector2f pos,
sfVector2f tile_size);
void update_battle_scene(battle_scene_t *scene, float time,
sfRenderWindow *window);
void draw_batle_scene(battle_scene_t *scene, sfRenderWindow *window);
void end_of_turn(player_t *player, hand_t *hand);
int is_point_in_polygon(sfVector2f *polygon, int nb_points, sfVector2f point);
sfVector2f *get_all_vector_from_vertex(sfVertexArray *array);
void add_pos(sfVector2f pos, sfVector2f *point);
void hover_card(sfEvent event, hand_t *hand);
void unclick_card(hand_t *hand, battle_scene_t *scene);
