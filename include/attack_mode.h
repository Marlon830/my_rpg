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
#include "project.h"

void analyse_events(sfRenderWindow *window, sfEvent event,
battle_scene_t *scene, hand_t *hand);
battle_scene_t *create_battle_scene(int width, int height,
sfVector2f tile_size);
void update_battle_scene(battle_scene_t *scene, project_t *project,
sfRenderWindow *window);
void draw_batle_scene(battle_scene_t *scene, sfRenderWindow *window,
project_t *project);
void end_of_turn(combat_player_t *player, hand_t *hand, battle_scene_t *scene);
int is_point_in_polygon(sfVector2f *polygon, int nb_points, sfVector2f point);
sfVector2f *get_all_vector_from_vertex(sfVertexArray *array);
void add_pos(sfVector2f pos, sfVector2f *point);
void hover_card(sfRenderWindow *window,sfEvent event, hand_t *hand);
void unclick_card(hand_t *hand, battle_scene_t *scene);
battle_scene_t *create_standard_battle_scene(void);
battle_scene_t *create_battle_scene_from_file(char *filename, char *enemy_file,
project_t *project);
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
void enemy_get_close_to_player(enemy_t *enemy, battle_scene_t *scene);
sfVector2f get_pos_in_tiles(combat_map_t *map, tile_t *tile);
void upscale_player_stats(player_stats_t *stats, sfVector2f scale);
void update_player_stats(player_stats_t *stats, stat_t *actual_stats);
void set_texture_equipment(equipment_t *equip);
lazer_t *create_lazer(sfVector2f start, sfVector2f end, float radius);
void destroy_lazer(lazer_t *lazer);
void draw_lazer(lazer_t *lazer, sfRenderWindow *window);
void update_lazer(lazer_t *lazer);
void append_vertex(sfVector2f point, sfColor color, sfVertexArray *array);
void update_black_fade(battle_scene_t *scene);
void update_end_of_fight(battle_scene_t *scene);
arrow_t *create_arrow(sfVector2f pos, float size);
void draw_arrow(arrow_t *arrow, sfRenderWindow *window);
sprite_t *create_sprite(char *filename, sfVector2f pos);
tutorial_t *create_tutorial(void);
void draw_tutorial(tutorial_t *tutorial, sfRenderWindow *window);
