/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** quest_draw.c
*/

#include "project.h"

void quest_draw(project_t *project)
{
    sfVector2f text_pos = {project->player->pos.x - 125,
    project->player->pos.y - 65};
    sfText_setPosition(project->quests->actual_quests_text, text_pos);
    sfText_setPosition(project->quests->finished_quests_text, text_pos);
    if (project->quests->is_act_disp == 1)
        sfRenderWindow_drawText(project->window,
        project->quests->actual_quests_text, NULL);
    else if (project->quests->is_act_disp == 0)
        sfRenderWindow_drawText(project->window,
        project->quests->finished_quests_text, NULL);
}
