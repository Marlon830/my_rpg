/*
** EPITECH PROJECT, 2022
** tiled-to-c
** File description:
** move_camera.c
*/

#include "../../include/project.h"

bool check_collision(project_t *project, scene_t *scene)
{
    list_t *tmp = scene->colliders;

    while (tmp != NULL) {
        if (sfFloatRect_intersects(project->player->col,
        ((collider_t *)tmp->element)->rect, NULL))
            return true;
        tmp = tmp->next;
    }
    return false;
}

void move_camera(project_t *project, scene_t *scene)
{
    project->player->pos.x += project->player->move.x;
    project->player->pos.y += project->player->move.y;
    project->player->col->left = project->player->pos.x;
    project->player->col->top = project->player->pos.y + 8;
    if (check_collision(project, scene)) {
        project->player->pos.x -= project->player->move.x;
        project->player->pos.y -= project->player->move.y;
        project->player->col->left = project->player->pos.x;
        project->player->col->top = project->player->pos.y + 8;
        return;
    }
    sfView_setCenter(scene->camera, project->player->pos);
    sfRenderWindow_setView(project->window, scene->camera);
    image_t *player = get_item(scene->images, "player");
    player->pos = project->player->pos;
    sfSprite_setPosition(player->sprite, player->pos);
}
