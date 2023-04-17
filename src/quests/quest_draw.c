/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** quest_draw.c
*/

#include "project.h"

void quest_draw(project_t *project)
{
    sfVector2f rect_pos = {project->player->pos.x - 125,
    project->player->pos.y - 65};
    sfVector2f text_pos = {rect_pos.x + 3, rect_pos.y + 2.5};
    sfText_setPosition(project->quests->actual_quests_text, text_pos);
    sfText_setPosition(project->quests->finished_quests_text, text_pos);
    sfRectangleShape_setPosition(project->quests->actual_quests_rect,
    rect_pos);
    sfRectangleShape_setPosition(project->quests->finished_quests_rect,
    rect_pos);
    if (project->quests->is_act_disp == 1) {
        sfRenderWindow_drawRectangleShape(WINDOW,
        project->quests->actual_quests_rect, NULL);
        sfRenderWindow_drawText(project->window,
        project->quests->actual_quests_text, NULL);
    } else if (project->quests->is_act_disp == 0) {
        sfRenderWindow_drawRectangleShape(WINDOW,
        project->quests->finished_quests_rect, NULL);
        sfRenderWindow_drawText(project->window,
        project->quests->finished_quests_text, NULL);
    }
}
