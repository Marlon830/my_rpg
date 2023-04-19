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
#include "utils.h"

void analyse_events(sfRenderWindow *window, sfEvent event,
battle_scene_t *scene, hand_t *hand);
battle_scene_t *create_battle_scene(int width, int height,
sfVector2f tile_size);
void update_battle_scene(battle_scene_t *scene, float time,
sfRenderWindow *window);
void draw_batle_scene(battle_scene_t *scene, sfRenderWindow *window);
void end_of_turn(combat_player_t *player, hand_t *hand, battle_scene_t *scene);
int is_point_in_polygon(sfVector2f *polygon, int nb_points, sfVector2f point);
sfVector2f *get_all_vector_from_vertex(sfVertexArray *array);
void add_pos(sfVector2f pos, sfVector2f *point);
void hover_card(sfEvent event, hand_t *hand);
void unclick_card(hand_t *hand, battle_scene_t *scene);
battle_scene_t *create_standard_battle_scene(void);
battle_scene_t *create_battle_scene_from_file(char *filename, char *enemy_file);
sfText *setup_text(char *text, sfVector2f pos, int police_size);
void destroy_card_overlay(card_overlay_t *overlay);
card_overlay_t *create_card_overlay(card_t *card);
void draw_card_overlay(card_overlay_t *overlay, sfRenderWindow *window);
void update_card_overlay(card_overlay_t *overlay, card_t *card);
int is_there_an_enemy(tile_t *tile, enemy_t **enemies, int nb_enemies);
void enemy_attack(enemy_t *enemy, battle_scene_t *scene);
tile_t **get_enemy_tiles_close(battle_scene_t *scene, tile_t *tile, int dist,
enemy_t *enemy);
int count_nb_tiles(battle_scene_t *scene, combat_map_t *map,
tile_t *tile, int dist);
void is_good_height(tile_t *tile1, tile_t *tile2,
sfVector2f *pos, battle_scene_t *scene);
void set_close_tiles(tile_t **tiles, tile_t *pos, int b, int len);
void set_enemy_pos(enemy_t *enemy);
void set_player_stats(combat_player_t *player);
