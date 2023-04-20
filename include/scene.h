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

typedef struct button_s {
    sfVector2f position;
    sfVector2f size;
    sfRectangleShape *rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture_hover;
    sfBool (*is_clicked)(project_t *project, struct button_s *button,
    sfMouseButtonEvent *evt);
    void (*clicked)(project_t *project);
    void (*update)(struct button_s *button, project_t *project);
} button_t;

typedef struct image_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f sprite_size;
    sfVector2f sprite_pos;
    int curr_pos;
    int nb_sprite;
    sfClock *clock_image;
    sfTime time_image;
    float seconds_image;
} image_t;

typedef struct collider_s {
    sfFloatRect *rect;
} collider_t;

typedef struct tp_s {
    sfFloatRect rect;
    int to_scene_id;
    sfVector2f tp_pos;
} tp_t;

typedef struct scene_s {
    sfView *camera;
    list_t *images;
    list_t *colliders;
    char *path;
    char *name;
    list_t *tp;
    int nb_tp;
    list_t *pnj;
    sfVector2f map_size;
} scene_t;

typedef struct map_s {
    char *name;
    list_t *tp;
    int nb_tp;
    int nb_pnj;
    list_t *pnj;
    sfVector2f size;
} map_t;

void scene_draw(project_t *project, scene_t *scene);
void dialogue_draw(project_t *project);
void scene_event(project_t *project);
scene_t *load_scene(project_t *project, int scene_id);
void scene_destroy(scene_t *scene);
void move_camera(project_t *project, scene_t *scene);
image_t *create_image(sfVector2f pos, char *path, sfIntRect rect,
sfVector2f size);
collider_t *create_collider(int x, int y, int w, int h);
void colliders_init(char *path, scene_t *scene);
void images_destroy(image_t *image);
void colliders_destroy(scene_t *scene);
map_t *get_map(char *map_name);
sfText *create_text(sfVector2f pos, sfVector2f size, sfColor color);
sfRectangleShape *create_rect(void);
tp_t *create_tp(sfVector2f pos, sfVector2f tp_pos, int to_scene_id);
void images_draw(project_t *project, list_t *img_list);
void update_button(button_t *btn, project_t *project);
button_t *create_button(sfVector2f position , sfVector2f size,
char *path, void (*clicked)(project_t *project));
void draw_button(button_t *btn, project_t *project);
void new_save(project_t *project);
#endif
