/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** project.h
*/

#ifndef PROJECT_H_
    #define PROJECT_H_
    #include "graphic.h"
    #include "utils.h"

    #define WINDOW project->graphic->window

typedef struct project_s {
    graphic_t *graphic;
    float player_speed;
} project_t;

#endif
