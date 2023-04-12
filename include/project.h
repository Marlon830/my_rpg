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

typedef struct actual_dialogue_s {
    char *dialogue;
    int pos;
    sfText *text;
    sfRectangleShape *rect;
    int is_displayed;
    image_t *face;
} act_dial_t;

typedef struct project_s {
    sfRenderWindow *window;
    inventory_t *inventory;
    scene_t *scene;
    sfClock *clock;
    list_t *all_dialogues;
    act_dial_t *actual_dial;
    float dt;
    player_t *player;
    int scene_id;
} project_t;

void update_scene(project_t *project);

list_t *create_all_dialogues(project_t *project, char *path_to_all_dialogue);
char *get_dialogue_by_id(project_t *project, list_t *dialogue, char *id);
char *get_dialogue_image(char *dialogue);
void display_dialogue(project_t *project);

#endif
