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

void scene_draw(project_t *project, scene_t *scene)
{
    sfRenderWindow_clear(project->window, sfBlack);
    images_draw(project, scene->images);
}
