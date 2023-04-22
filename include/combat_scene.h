/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my.h
*/

#pragma once

#include "attack_structs.h"

#define MIN(a,b) a < b ? a : b
#define MAX(a,b) a > b ? a : b
#define GET_MAX_TILES(n) n * n + 2 * n + 1


sfvertex vertex_create(sfVector2f position, sfColor color);
tile_t *create_tile(sfVector2f center, sfColor color,
sfVector2f size, float height);
void draw_tile(sfRenderWindow *window, tile_t *tile);
void update_tile(tile_t *tile);
sfVector2f *get_points(tile_t *tile);
int is_point_in_diamond(sfVector2f point, tile_t *tile);
combat_map_t *create_map(int width, int height, sfVector2f decalage,
sfVector2f size);
void update_map(sfRenderWindow *window, combat_map_t *map, sfEvent event);
void draw_map(sfRenderWindow *window, combat_map_t *map);
void add_walls(tile_t *tile);
void create_tile_array(sfVector2f center, sfColor color,
sfVector2f size, sfVertexArray *tile);
void change_height(float new_height, tile_t *tile);
float manhattan_dist(sfVector2f p1, sfVector2f p2);
int sign(float a);
void change_tiles(combat_map_t *map, sfVector2f new_size);

void wave_map(combat_map_t *map, float height);
void breathing_map(combat_map_t *map, float height);
void water_drop_map(combat_map_t *map);
void test_map(combat_map_t *map, float height);

combat_player_t *create_player(tile_t *tile);
void draw_player(combat_player_t *player, sfRenderWindow *window);
void set_player_pos(combat_player_t *player);
void update_player(combat_player_t *player, battle_scene_t *scene);
tile_t **get_tiles_close(battle_scene_t *scene, tile_t *tile, int dist,
combat_player_t *player);
tile_t **update_tiles_close(combat_player_t *player, battle_scene_t *scene,
tile_t *tile, int dist);
void color_tiles(combat_map_t *map, combat_player_t *player);
void random_map(combat_map_t *map);
int count_char_in_str(char *str, char c);
int my_getnbr(char *str);
combat_map_t *create_map_from_file(char *filename, sfVector2f size);
void save_map(combat_map_t *map, char *filename);
int my_strlen(char *str);
int int_len(int x);
stat_t *create_stats(int damage, int health_point, int move_point);
void move_player(combat_player_t *player, tile_t *tile,
battle_scene_t *scene);


int get_width_height(combat_map_t *map, FILE *stream);
combat_map_t *load_map(char *filename, sfVector2f size);
int count_char_until(char *str, char until);
tile_t *get_tile_from_str(char *line, sfVector2f size, sfVector2f decalage);
tile_t **get_tiles_attack(battle_scene_t *scene, tile_t *tile, int dist,
combat_player_t *player);

enemy_t *create_enemy(tile_t *tile, char *sprite_name);
enemy_t **create_random_enemies(combat_map_t *map, int nb_enemy);
void draw_enemy(enemy_t *enemy, sfRenderWindow *window);
enemy_t **create_enemies_from_txt(char *filename, combat_map_t *map,
int *nb_enemies);
void change_enemy_color(enemy_t *enemy);
void update_enemies(enemy_t **enemies, int nb_enemies, battle_scene_t *scene);
combat_text_t *create_combat_text(sfVector2f char_pos);
void update_damage_taken(combat_text_t *text);
char *int_to_str(int x);

void destroy_battle_scene(battle_scene_t *scene);
void destroy_player(combat_player_t *player);
void destroy_combat_text(combat_text_t *text);
void destroy_enemy(enemy_t *enemy);
void destroy_tile(tile_t *tile);
void destroy_map(combat_map_t *map);
void destroy_card(card_t *card);
void destroy_hand(hand_t *hand);
void destroy_battle_scene(battle_scene_t *scene);

void update_combat_text(char *str, sfText *text);
char *get_str_until(char *str, char sep);
void destroy_image(image_t *image);
