/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** combat_scene.h
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
#include "spells.h"
#include "combat_scene.h"



typedef struct battle_scene_s {
    player_t *player;
    map_t *map;
    hand_t *hand;
} battle_scene_t;

void analyse_events(sfRenderWindow *window, sfEvent event,
battle_scene_t *scene, hand_t *hand);
battle_scene_t *create_battle_scene(int width, int height, sfVector2f pos,
sfVector2f tile_size);
void update_battle_scene(battle_scene_t *scene, float time);
void draw_batle_scene(battle_scene_t *scene, sfRenderWindow *window);
void end_of_turn(player_t *player, hand_t *hand);
