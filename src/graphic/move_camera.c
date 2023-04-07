/*
** EPITECH PROJECT, 2022
** tiled-to-c
** File description:
** move_camera.c
*/

#include "../../include/project.h"

bool check_collision(project_t *project)
{
    list_t *tmp = project->graphic->colliders;
    while (tmp != NULL) {
        if (sfFloatRect_intersects(project->graphic->player_col,
        ((collider_t *)tmp->element)->rect, NULL))
            return true;
        tmp = tmp->next;
    }
    return false;
}

void move_camera(graphic_t *graphic, project_t *project)
{
    graphic->player_pos.x += project->movement.x;
    graphic->player_pos.y += project->movement.y;
    graphic->player_col->left = graphic->player_pos.x;
    graphic->player_col->top = graphic->player_pos.y;
    if (check_collision(project)) {
        graphic->player_pos.x -= project->movement.x;
        graphic->player_pos.y -= project->movement.y;
        graphic->player_col->left = graphic->player_pos.x;
        graphic->player_col->top = graphic->player_pos.y;
        return;  
    }
    sfView_setCenter(graphic->camera, graphic->player_pos);
    sfRenderWindow_setView(graphic->window, graphic->camera);
    image_t *player = get_item(graphic->images, "player");
    player->pos = graphic->player_pos;
    sfSprite_setPosition(player->sprite, player->pos);
}
