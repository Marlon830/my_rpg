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

    #define WINDOW project->window

typedef struct project_s {
    sfRenderWindow *window;
    graphic_t *scene_one;
    sfClock *clock;
    float dt;
    int scene_id;
} project_t;

void update_all_scenes(project_t *project);
void update_scene_one(project_t *project, graphic_t *scene);

#endif
