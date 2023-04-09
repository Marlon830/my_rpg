/*
** EPITECH PROJECT, 2022
** tiled-to-c
** File description:
** move_camera.c
*/

#include "../../include/project.h"

bool check_collision(project_t *project, graphic_t *scene)
{
    list_t *tmp = scene->colliders;

    while (tmp != NULL) {
        if (sfFloatRect_intersects(scene->player_col,
        ((collider_t *)tmp->element)->rect, NULL))
            return true;
        tmp = tmp->next;
    }
    return false;
}

void move_camera(project_t *project, graphic_t *scene)
{
    scene->player_pos.x += scene->movement.x;
    scene->player_pos.y += scene->movement.y;
    scene->player_col->left = scene->player_pos.x;
    scene->player_col->top = scene->player_pos.y;
    if (check_collision(project, scene)) {
        scene->player_pos.x -= scene->movement.x;
        scene->player_pos.y -= scene->movement.y;
        scene->player_col->left = scene->player_pos.x;
        scene->player_col->top = scene->player_pos.y;
        return;
    }
    sfView_setCenter(scene->camera, scene->player_pos);
    sfRenderWindow_setView(project->window, scene->camera);
    image_t *player = get_item(scene->images, "player");
    player->pos = scene->player_pos;
    sfSprite_setPosition(player->sprite, player->pos);
}
