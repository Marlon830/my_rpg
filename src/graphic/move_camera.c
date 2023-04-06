/*
** EPITECH PROJECT, 2022
** tiled-to-c
** File description:
** move_camera.c
*/

#include "../../include/graphic.h"

void move_camera(graphic_t *graphic, sfVector2f move, sfKeyCode key)
{
    graphic->player_pos.x += move.x;
    graphic->player_pos.y += move.y;
    sfView_setCenter(graphic->camera, graphic->player_pos);
    sfRenderWindow_setView(graphic->window, graphic->camera);
    image_t *player = get_item(graphic->images, "player");
    player->pos = graphic->player_pos;
    sfSprite_setPosition(player->sprite, player->pos);
}
