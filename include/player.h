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

typedef struct player_s {
    sfVector2f pos;
    sfFloatRect *col;
    float speed;
    sfVector2f move;
} player_t;

#endif
