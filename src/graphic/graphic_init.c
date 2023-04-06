/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** graphic_init.c
*/

#include "../../include/graphic.h"

graphic_t *graphic_init(void)
{
    graphic_t *graphic = malloc(sizeof(graphic_t));
    sfVideoMode mode = (sfVideoMode){1920, 1080, 32};

    graphic->window = sfRenderWindow_create(mode, "Quoi ? Feur", sfClose | sfFullscreen, NULL);
    graphic->camera = sfView_create();
    graphic->player_pos = (sfVector2f){160, 160};
    graphic->images = malloc(sizeof(list_t));
    graphic->images = NULL;
    sfView_setSize(graphic->camera, (sfVector2f){256,144});
    sfView_setCenter(graphic->camera, graphic->player_pos);
    sfRenderWindow_setView(graphic->window, graphic->camera);
    push_back(&graphic->images, "map", create_image(0,
    0, "basic.png", (sfIntRect){0,0, 320, 320}), IMAGE);
    push_back(&graphic->images, "player", create_image(graphic->player_pos.x,
    graphic->player_pos.y, "player.png", (sfIntRect){0,0, 16, 16}), IMAGE);
    return graphic;
}
