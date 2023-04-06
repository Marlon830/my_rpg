/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my.h
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/System.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define MIN(a,b) a < b ? a : b
#define MAX(a,b) a > b ? a : b
#define GET_MAX_TILES(n) n * n + 2 * n + 1

typedef struct tile_s {
    sfVertexArray *array_tile;
    sfVertexArray *array_walls;
    sfVector2f *points;
    sfVector2f pos;
    int ind;
    sfVector2f size;
    sfColor color;
    float height;
} tile_t;

typedef struct {
    int move_points;
    float health_point;
    float damage;
} stat_t;

typedef struct {
    sfVector2f pos;
    sfVector2f mousePos;
    tile_t **tiles;
    tile_t *hovered_tile;
    int width;
    int height;
} map_t;

typedef struct {
    tile_t *actual_tile;
    sfVertexArray *array_character;
    stat_t *basic_stats;
    stat_t *actual_stats;
    tile_t **tiles_close;
    int nb_tiles_close;
} player_t;

typedef struct battle_scene_s {
    player_t *player;
    map_t *map;
} battle_scene_t;

void analyse_events(sfRenderWindow *window, sfEvent event,
battle_scene_t *scene);
sfVertex create_vertex(sfVector2f position, sfColor color);
tile_t *create_tile(sfVector2f center, sfColor color,
sfVector2f size, float height);
void draw_tile(sfRenderWindow *window, tile_t *tile);
void update_tile(tile_t *tile);
sfVector2f *get_points(tile_t *tile);
int is_point_in_diamond(sfVector2f point, tile_t *tile);
map_t *create_map(int width, int height, sfVector2f decalage,
sfVector2f size);
void update_map(map_t *map, sfEvent event, player_t *player);
void draw_map(sfRenderWindow *window, map_t *map);
void add_walls(tile_t *tile);
void *create_tile_array(sfVector2f center, sfColor color,
sfVector2f size, sfVertexArray *tile);
void change_height(float new_height, tile_t *tile);
float manhattan_dist(sfVector2f p1, sfVector2f p2);
int sign(float a);
void change_tiles(map_t *map, sfVector2f new_size);

void wave_map(map_t *map, float height);
void breathing_map(map_t *map, float height);
void water_drop_map(map_t *map, float height);
void test_map(map_t *map, float height);

player_t *create_player(tile_t *tile);
void draw_player(player_t *player, sfRenderWindow *window);
void set_player_pos(player_t *player);
void update_player(player_t *player);
tile_t **get_tiles_close(map_t *map, tile_t *tile, int dist, player_t *player);
tile_t **update_tiles_close(player_t *player, map_t *map,
tile_t *tile, int dist);
void color_tiles(map_t *map, player_t *player);
void random_map(map_t *map, float height);
int count_char_in_str(char *str, char c);
int my_getnbr(char *str);
map_t *create_map_from_file(char *filename, sfVector2f size, sfVector2f pos);
void save_map(map_t *map);
int my_strlen(char *str);
int int_len(int x);
stat_t *create_stats(void);
void move_player(player_t *player, tile_t *tile, map_t *map);
void end_of_turn(player_t *player);

int get_width_height(map_t *map, char *text_information);
map_t *load_map(char *filename, sfVector2f size, sfVector2f pos);
char *get_line(char *str, int ind);
int count_char_until(char *str, char until);
tile_t *get_tile_from_str(char *line, sfVector2f size, sfVector2f decalage);
battle_scene_t *create_battle_scene(int width, int height, sfVector2f pos,
sfVector2f tile_size);
void update_battle_scene(battle_scene_t *scene, float time);
void draw_batle_scene(battle_scene_t *scene, sfRenderWindow *window);
