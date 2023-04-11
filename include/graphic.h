/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** graphic.h
*/

#ifndef GRAPHIC_H_
    #define GRAPHIC_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include "utils.h"

typedef struct project_s project_t;

typedef struct image_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} image_t;

typedef struct collider_s {
    sfFloatRect *rect;
} collider_t;

typedef struct graphic_s {
    sfView *camera;
    sfVector2f player_pos;
    sfFloatRect *player_col;
    list_t *images;
    list_t *colliders;
    float player_speed;
    sfVector2f movement;
} graphic_t;

void graphic_draw(project_t *project, graphic_t *scene);
void event_scene_one(project_t *project, graphic_t *scene);
void event_all_scenes(project_t *project);
graphic_t *graphic_init(project_t *project, char *map, char *collision,
    char *player);
void graphic_destroy(graphic_t *scene);
void move_camera(project_t *project, graphic_t *scene);
image_t *create_image(int x, int y, char *path, sfIntRect rect);
collider_t *create_collider(int x, int y, int w, int h);
void colliders_init(char *path, graphic_t *scene);

#endif
