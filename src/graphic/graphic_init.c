/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** graphic_init.c
*/

#include "../../include/graphic.h"

void next_graphic_init(graphic_t *graphic)
{
    graphic->player_col->width = 16;
    graphic->player_col->height = 16;
    sfView_setSize(graphic->camera, (sfVector2f){256,144});
    sfView_setCenter(graphic->camera, graphic->player_pos);
    sfRenderWindow_setView(graphic->window, graphic->camera);
    push_back(&graphic->images, "map", create_image(0,
    0, "spawn.png", (sfIntRect){0,0, 480, 480}), IMAGE);
    push_back(&graphic->images, "player", create_image(graphic->player_pos.x,
    graphic->player_pos.y, "player.png", (sfIntRect){0,0, 16, 16}), IMAGE);
    colliders_init("./assets/res.coll", graphic);
}

graphic_t *graphic_init(void)
{
    graphic_t *graphic = malloc(sizeof(graphic_t));
    sfVideoMode mode = (sfVideoMode){1920, 1080, 32};

    graphic->window = sfRenderWindow_create(mode, "Quoi ? Feur",
    sfClose | sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(graphic->window, 60);
    sfRenderWindow_setKeyRepeatEnabled(graphic->window, sfFalse);
    graphic->camera = sfView_create();
    graphic->player_pos = (sfVector2f){160, 160};
    graphic->images = malloc(sizeof(list_t));
    graphic->images = NULL;
    graphic->colliders = NULL;
    graphic->player_col = malloc(sizeof(sfFloatRect));
    graphic->player_col->left = graphic->player_pos.x;
    graphic->player_col->top = graphic->player_pos.y;
    next_graphic_init(graphic);
    return graphic;
}
