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

typedef struct graphic_s {
    sfRenderWindow *window;
    sfView *camera;
    sfVector2f player_pos;
    list_t *images;
} graphic_t;

graphic_t *graphic_init(void);
void graphic_draw(graphic_t *graphic);
void graphic_event(project_t *project);
graphic_t *graphic_init(void);
void graphic_event(project_t *project);
void graphic_destroy(graphic_t *graphic);
void move_camera(graphic_t *graphic, sfVector2f move, sfKeyCode key);
image_t *create_image(int x, int y, char *path, sfIntRect rect);

#endif
