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
    sfVector2f sprite_size;
    sfVector2f sprite_pos;
    int curr_pos;
    int nb_sprite;
} image_t;

typedef struct collider_s {
    sfFloatRect *rect;
} collider_t;

typedef struct spawn_s {
    sfFloatRect rect;
    int to_scene_id;
    sfVector2f tp_pos;
} spawn_t;

typedef struct scene_s {
    sfView *camera;
    list_t *images;
    list_t *colliders;
    char *path;
    char *name;
    spawn_t *tp;
    int nb_tp;
} scene_t;

typedef struct scene_list_s {
    char *name;
    spawn_t *tp;
    int nb_tp;
    sfVector2f size;
} scene_list_t;

void scene_draw(project_t *project, scene_t *scene);
void scene_event(project_t *project);
scene_t *load_scene(project_t *project, int scene_id);
void scene_destroy(scene_t *scene);
void move_camera(project_t *project, scene_t *scene);
image_t *create_image(sfVector2f pos, char *path, sfIntRect rect,
sfVector2f size);
collider_t *create_collider(int x, int y, int w, int h);
void colliders_init(char *path, scene_t *scene);
void images_destroy(scene_t *scene);
void colliders_destroy(scene_t *scene);
sfText *create_text(void);
sfRectangleShape *create_rect(void);

#endif
