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
    graphic_t *scene_two;
    sfClock *clock;
    list_t *all_dialogues;
    float dt;
    int scene_id;
} project_t;

void update_all_scenes(project_t *project);
void update_scene_one(project_t *project, graphic_t *scene);
void update_scene_two(project_t *project, graphic_t *scene);

#endif
