/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** scene.h
*/

#ifndef SCENE_H_
    #define SCENE_H_
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

typedef struct scene_s {
    sfView *camera;
    list_t *images;
    list_t *colliders;
    sfVector2f spawn;
    char *path;
    char *name;
} scene_t;

typedef struct scene_list_s {
    char *name;
    sfVector2f spawn;
} scene_list_t;

void scene_draw(project_t *project, scene_t *scene);
void scene_event(project_t *project);
scene_t *load_scene(project_t *project, int scene_id);
void scene_destroy(scene_t *scene);
void move_camera(project_t *project, scene_t *scene);
image_t *create_image(int x, int y, char *path, sfIntRect rect);
collider_t *create_collider(int x, int y, int w, int h);
void colliders_init(char *path, scene_t *scene);

#endif
