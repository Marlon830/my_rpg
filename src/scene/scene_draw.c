/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** scene_draw.c
*/

#include "project.h"

void img_animation(project_t *project, image_t *img)
{
    if ((int)project->dt % 20 == 0 && img->nb_sprite > 1) {
        img->curr_pos++;
        if (img->curr_pos == img->nb_sprite)
            img->curr_pos = 0;
    }
    img->sprite_pos.x = img->sprite_size.x * img->curr_pos;
}

void images_draw(project_t *project, list_t *img_list)
{
    list_t *tmp = img_list;
    image_t *img;

    while (tmp != NULL) {
        img = tmp->element;
        img_animation(project, img);
        sfSprite_setTextureRect(((image_t *)tmp->element)->sprite,
        (sfIntRect){img->sprite_pos.x, img->sprite_pos.y, img->sprite_size.x,
        img->sprite_size.y});
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
