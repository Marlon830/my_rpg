/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player.h
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include "utils.h"

enum player_state {
    IDLE_DOWN,
    IDLE_UP,
    IDLE_LEFT,
    IDLE_RIGHT,
    RUN_DOWN,
    RUN_UP,
    RUN_LEFT,
    RUN_RIGHT
};

typedef struct player_s {
    sfVector2f pos;
    sfFloatRect *col;
    float speed;
    enum player_state state;
    sfVector2f move;
    int player_progress_state;
} player_t;

#endif
