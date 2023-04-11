/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** project.h
*/

#ifndef PROJECT_H_
    #define PROJECT_H_
    #include "scene.h"
    #include "utils.h"
    #include "inventory.h"
    #include "player.h"


    #define WINDOW project->window

typedef struct project_s {
    sfRenderWindow *window;
    inventory_t *inventory;
    scene_t *scene;
    sfClock *clock;
    float dt;
    player_t *player;
    int scene_id;
} project_t;

void update_scene(project_t *project);

#endif
