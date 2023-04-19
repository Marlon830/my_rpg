/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** quest_draw.c
*/

#include "project.h"

void quest_draw_ter(project_t *project, sfFloatRect rect_size,
    sfVector2f rect_pos, int finish_len)
{
    if (project->quests->is_act_disp == 0) {
        sfRectangleShape_setSize(project->quests->finished_quests_rect,
        (sfVector2f) {rect_size.width, 3.5 * finish_len + 3.5});
        sfText_setPosition(project->quests_button, (sfVector2f)
        {rect_pos.x, rect_pos.y + (3.5 * finish_len + 3.5)});
        sfRenderWindow_drawRectangleShape(WINDOW,
        project->quests->finished_quests_rect, NULL);
        sfRenderWindow_drawText(project->window,
        project->quests->finished_quests_text, NULL);
    }
    sfRenderWindow_drawText(WINDOW, project->quests_button, NULL);
}

void quest_draw_bis(project_t *project, sfVector2f rect_pos)
{
    sfFloatRect rect_size =
    sfRectangleShape_getGlobalBounds(project->quests->actual_quests_rect);
    int act_len = get_list_len(project->quests->actual_quests_list);
    int finish_len = get_list_len(project->quests->finished_quests_list);

    if (project->quests->is_act_disp == 1) {
        sfRectangleShape_setSize(project->quests->actual_quests_rect,
        (sfVector2f) {rect_size.width, 3.5 * act_len + 3.5});
        sfText_setPosition(project->quests_button, (sfVector2f)
        {rect_pos.x, rect_pos.y + (3.5 * act_len + 3.5)});
        sfRenderWindow_drawRectangleShape(WINDOW,
        project->quests->actual_quests_rect, NULL);
        sfRenderWindow_drawText(project->window,
        project->quests->actual_quests_text, NULL);
    }
    quest_draw_ter(project, rect_size, rect_pos, finish_len);
}

void quest_draw(project_t *project)
{
    sfVector2f rect_pos = {project->player->pos.x - 125,
    project->player->pos.y - 65};
    sfVector2f text_pos = {rect_pos.x + 3, rect_pos.y + 2.5};

    sfText_setPosition(project->quests->actual_quests_text, text_pos);
    sfText_setPosition(project->quests->finished_quests_text, text_pos);
    sfText_setPosition(project->quests_button, text_pos);
    sfRectangleShape_setPosition(project->quests->actual_quests_rect,
    rect_pos);
    sfRectangleShape_setPosition(project->quests->finished_quests_rect,
    rect_pos);
    quest_draw_bis(project, rect_pos);
}
