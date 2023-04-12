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

typedef struct player_s player_t;
typedef struct battle_scene_s battle_scene_t;
typedef struct card_s card_t;
typedef struct hand_s hand_t;
typedef sfVertex sfvertex;
typedef struct tile_s tile_t;
typedef struct stat_s stat_t;
typedef struct map_s map_t;

enum player_state_e {
    ATTACKING,
    WAITING,
    MOVING,
};

typedef enum card_state_e {
    NONE,
    HOVERED,
    SELECTED
} card_state;

struct card_s {
    player_t *player;
    sfVector2f pos;
    sfVertexArray *array;
    char *name;
    int range;
    int energy;
    int damage;
    struct card_s *next;
    struct card_s *previous;
    enum card_state_e state;
};

struct hand_s {
    player_t *player;
    card_t *cards;
    card_t *selected;
    int nb_cards;
};


struct player_s {
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
};


struct battle_scene_s {
    player_t *player;
    map_t *map;
    hand_t *hand;
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
};

struct map_s {
    sfVector2f pos;
    sfVector2f mousePos;
    tile_t **tiles;
    tile_t *hovered_tile;
    tile_t *far_tile;
    int width;
    int height;
};
