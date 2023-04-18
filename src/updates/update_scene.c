/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_scene.c
*/

#include "project.h"

sfVector2f key_management(project_t *project)
{
    sfVector2f pos = {0, 0};
    if (project->inventory->is_active || project->actual_dial->is_displayed)
        return pos;
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        pos.y -= project->player->speed;
        project->player->state = RUN_UP;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        pos.y += project->player->speed;
        project->player->state = RUN_DOWN;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        pos.x -= project->player->speed;
        project->player->state = RUN_LEFT;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        pos.x += project->player->speed;
        project->player->state = RUN_RIGHT;
    }
    return pos;
}

void update_pnj(project_t *project, image_t *player)
{
    list_t *temp_pnj = project->scene->pnj;

    while (temp_pnj != NULL) {
        all_pnjs_t *act_pnj = (all_pnjs_t *) temp_pnj->element;
        if (sfFloatRect_contains(act_pnj->hitbox,
        player->pos.x, player->pos.y)) {
            act_pnj->sprite->sprite_pos.y = 16;
            act_pnj->can_talk = 1;
        } else {
            act_pnj->can_talk = 0;
            act_pnj->sprite->sprite_pos.y = 0;
        }
        temp_pnj = temp_pnj->next;
    }
}

void update_scene(project_t *project)
{
    image_t *player = get_item(project->scene->images, "player");
    sfVector2f movement = key_management(project);

    update_pnj(project, player);
    project->dt = sfTime_asMilliseconds(sfClock_getElapsedTime(project->clock));
    if (movement.x != 0 || movement.y != 0) {
        project->player->move.x = movement.x;
        project->player->move.y = movement.y;
        player->sprite_pos.y = project->player->state * 32;
        move_camera(project, project->scene);
    } else {
        if (project->player->state > 3) {
            project->player->state -= 4;
            player->sprite_pos.y = project->player->state * 32;
        }
    }
    scene_draw(project, project->scene);
    update_inventory(project);
}
