/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** scene_draw.c
*/

#include "project.h"

void img_animation(image_t *img)
{
    img->time_image = sfClock_getElapsedTime(img->clock_image);
    img->seconds_image = img->time_image.microseconds / 1000000.0;
    if (img->seconds_image > 0.15 && img->nb_sprite > 1) {
        img->curr_pos++;
        if (img->curr_pos == img->nb_sprite)
            img->curr_pos = 0;
        sfClock_restart(img->clock_image);
    }
    img->sprite_pos.x = img->sprite_size.x * img->curr_pos;
}

void images_draw(project_t *project, list_t *img_list)
{
    list_t *tmp = img_list;
    image_t *img;

    while (tmp != NULL) {
        img = tmp->element;
        img_animation(img);
        sfSprite_setTextureRect(((image_t *)tmp->element)->sprite,
        (sfIntRect){img->sprite_pos.x, img->sprite_pos.y, img->sprite_size.x,
        img->sprite_size.y});
        sfRenderWindow_drawSprite(project->window,
        ((image_t *)tmp->element)->sprite, NULL);
        if (!my_strcmp("player", tmp->id))
            draw_equipment(project, project->player);
        tmp = tmp->next;
    }
}

void collision_draw(project_t *project, list_t *coll_list)
{
    list_t *tmp = coll_list;
    collider_t *col;
    sfRectangleShape *rect;

    while (tmp != NULL) {
        col = tmp->element;
        rect = sfRectangleShape_create();
        sfRectangleShape_setPosition(rect, (sfVector2f){col->rect->left,
        col->rect->top});
        sfRectangleShape_setSize(rect, (sfVector2f){16, 16});
        sfRectangleShape_setFillColor(rect, (sfColor){255,0,0,100});
        sfRenderWindow_drawRectangleShape(project->window, rect, NULL);
        tmp = tmp->next;
    }
}

void tp_draw(project_t *project, list_t *tp_list)
{
    list_t *tmp = tp_list;
    tp_t *tp;
    sfRectangleShape *rect;

    while (tmp != NULL) {
        tp = tmp->element;
        rect = sfRectangleShape_create();
        sfRectangleShape_setPosition(rect, (sfVector2f){tp->rect.left,
        tp->rect.top});
        sfRectangleShape_setSize(rect, (sfVector2f){16, 16});
        sfRectangleShape_setFillColor(rect, (sfColor){255,255,255,100});
        sfRenderWindow_drawRectangleShape(project->window, rect, NULL);
        tmp = tmp->next;
    }
}

void scene_draw(project_t *project, scene_t *scene)
{
    sfRenderWindow_clear(project->window, sfBlack);
    images_draw(project, scene->images);
    dialogue_draw(project);
    quest_draw(project);
}
