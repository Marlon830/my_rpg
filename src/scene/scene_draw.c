/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** scene_draw.c
*/

#include "project.h"

void images_draw(project_t *project, list_t *img_list)
{
    list_t *tmp = img_list;

    while (tmp != NULL) {
        sfRenderWindow_drawSprite(project->window,
        ((image_t *)tmp->element)->sprite, NULL);
        tmp = tmp->next;
    }
}

void dialogue_draw(project_t *project)
{
    sfVector2f player_pos = {project->player->pos.x - 100,
    project->player->pos.y + 35};

    if (project->actual_dial->is_displayed == 1) {
        sfSprite_setPosition(project->actual_dial->face->sprite,
        (sfVector2f) {player_pos.x + 175, player_pos.y + 3});
        sfText_setPosition(project->actual_dial->text, player_pos);
        sfRectangleShape_setPosition(project->actual_dial->rect, player_pos);
        sfRenderWindow_drawRectangleShape(project->window,
        project->actual_dial->rect, NULL);
        sfRenderWindow_drawText(project->window,
        project->actual_dial->text, NULL);
        sfRenderWindow_drawSprite(project->window,
        project->actual_dial->face->sprite, NULL);
    }
}

void scene_draw(project_t *project, scene_t *scene)
{
    sfRenderWindow_clear(project->window, sfBlack);
    images_draw(project, scene->images);
    dialogue_draw(project);
}
