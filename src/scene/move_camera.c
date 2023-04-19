/*
** EPITECH PROJECT, 2022
** tiled-to-c
** File description:
** move_camera.c
*/

#include "project.h"

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

bool check_tp(project_t *project)
{
    list_t *tmp = project->scene->tp;
    tp_t *tp;

    while (tmp) {
        tp = tmp->element;
        if (sfFloatRect_intersects(project->player->col,
        &tp->rect, NULL)) {
            sfVector2f pos = tp->tp_pos;
            project->player->pos = pos;
            project->player->col->left = project->player->pos.x + 11;
            project->player->col->top = project->player->pos.y + 16;
            project->scene = load_scene(project, tp->to_scene_id);
            change_state_with_scene(project, tp->to_scene_id);
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void move_camera(project_t *project, scene_t *scene)
{
    image_t *player = get_item(scene->images, "player");

    project->player->pos.x += project->player->move.x;
    project->player->pos.y += project->player->move.y;
    project->player->col->left = project->player->pos.x + 11;
    project->player->col->top = project->player->pos.y + 16;
    if (!check_tp(project) && check_collision(project, scene)) {
        project->player->pos.x -= project->player->move.x;
        project->player->pos.y -= project->player->move.y;
        project->player->col->left = project->player->pos.x + 11;
        project->player->col->top = project->player->pos.y + 16;
        return;
    }
    sfView_setCenter(scene->camera, project->player->pos);
    sfRenderWindow_setView(project->window, scene->camera);
    player->pos = project->player->pos;
    sfSprite_setPosition(player->sprite, player->pos);
}
