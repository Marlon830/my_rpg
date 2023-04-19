/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** quest_event.c
*/

#include "project.h"

void quest_event(project_t *project, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
        project->quests->is_act_disp = 1;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF)
        project->quests->is_act_disp = 0;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE)
        project->quests->is_act_disp = -1;
}
