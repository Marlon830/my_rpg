/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** attack_structs.h
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
#include "scene.h"

typedef struct combat_player_s combat_player_t;
typedef struct battle_scene_s battle_scene_t;
typedef struct card_s card_t;
typedef struct hand_s hand_t;
typedef sfVertex sfvertex;
typedef struct tile_s tile_t;
typedef struct stat_s stat_t;
typedef struct combat_map_s combat_map_t;
typedef struct enemy_s enemy_t;
typedef struct combat_text_s combat_text_t;
typedef struct card_overlay_s card_overlay_t;
typedef struct equipment_s equipment_t;
typedef struct lazer_s lazer_t;
typedef struct arrow_s arrow_t;
typedef struct sprite_s sprite_t;
typedef struct tutorial_s tutorial_t;

#define pi 3.1415

enum player_state_e {
    ATTACKING,
    WAITING,
    MOVING,
};

typedef enum card_state_e {
    NOTHING,
    HOVERED,
    SELECTED
} card_state;

struct card_overlay_s {
    sfText *damage;
    sfText *energy;
    sfText *range;
    sfSprite *sprite;
    sfText *name;
    sprite_t *damage_sprite;
    sprite_t *energy_sprite;
    sprite_t *range_sprite;
};

struct card_s {
    combat_player_t *player;
    sfVector2f pos;
    sfVertexArray *array;
    char *name;
    int range;
    int energy;
    int damage;
    float angle;
    struct card_s *next;
    struct card_s *previous;
    enum card_state_e state;
    card_overlay_t *overlay;
};

struct hand_s {
    combat_player_t *player;
    card_t *cards;
    card_t *selected;
    int nb_cards;
};


struct combat_player_s {
    tile_t *actual_tile;
    sfVertexArray *array_character;
    stat_t *basic_stats;
    stat_t *actual_stats;
    tile_t **tiles_close;
    tile_t **attack_tiles;
    int nb_tiles_close;
    int nb_attack_tiles;
    enum player_state_e state;
    card_t *card;
    combat_text_t *damage_taken;
    combat_text_t **overlay;
    image_t *sprite;
    equipment_t *equipment;
};

struct arrow_s {
    sfVertexArray *array;
    sfVector2f pos;
    sfText *text;
    float size;
    float angle;
};


struct battle_scene_s {
    combat_player_t *player;
    combat_map_t *map;
    hand_t *hand;
    enemy_t **enemies;
    int nb_enemies;
    int win;
    sfView *view;
    lazer_t *lazer;
    sfClock *clock;
    sfVertexArray *black_fade;
    tutorial_t *tutorial;
};

struct tile_s {
    sfVertexArray *array_tile;
    sfVertexArray *array_walls;
    sfVector2f *points;
    sfVector2f pos;
    int ind;
    sfVector2f size;
    sfColor color;
    float height;
};

struct stat_s {
    int move_points;
    float health_point;
    float damage;
    int energy_points;
    int defense;
};

struct combat_map_s {
    sfVector2f pos;
    sfVector2f mousePos;
    tile_t **tiles;
    tile_t *hovered_tile;
    tile_t *far_tile;
    int width;
    int height;
};

struct enemy_s {
    tile_t *actual_tile;
    sfVertexArray *array_character;
    stat_t *basic_stats;
    stat_t *actual_stats;
    tile_t **tiles_close;
    tile_t **attack_tiles;
    combat_text_t *damage_taken;
    int nb_tiles_close;
    int range;
    int nb_attack_tiles;
    image_t *sprite;
};

struct lazer_s {
    sfVertexArray *array;
    sfClock *clock;
    sfVector2f start;
    sfVector2f end;
    float radius;
    int show;
};

struct combat_text_s {
    sfText *text;
    sfClock *clock;
    int show;
};

struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
};

struct tutorial_s {
    sprite_t *left_click;
    sprite_t *right_click;
    sprite_t *space_bar;
    sfText *left_click_text;
    sfText *right_click_text;
    sfText *space_bar_text;
    arrow_t *arrow;
};
