/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** scene_draw_bis.c
*/

#include "project.h"

void dialogue_draw(project_t *project)
{
    sfVector2f player_pos = {project->player->pos.x - 100,
    project->player->pos.y + 35};
    sfVector2f player_pos_bis = {project->player->pos.x - 90,
    project->player->pos.y + 40};

    if (project->actual_dial->is_displayed == 1) {
        sfSprite_setPosition(project->actual_dial->face->sprite,
        (sfVector2f) {player_pos.x + 172, player_pos.y + 2});
        sfText_setPosition(project->actual_dial->text, player_pos_bis);
        sfRectangleShape_setPosition(project->actual_dial->rect,
        player_pos);
        sfRenderWindow_drawRectangleShape(project->window,
        project->actual_dial->rect, NULL);
        sfRenderWindow_drawText(project->window,
        project->actual_dial->text, NULL);
        sfRenderWindow_drawSprite(project->window,
        project->actual_dial->face->sprite, NULL);
    }
}
