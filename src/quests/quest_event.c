/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** quest_event.c
*/

#include "project.h"

void quest_event_bis(project_t *project, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF
    && project->quests->is_act_disp == 0) {
        project->quests->is_act_disp = -1;
        return;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF
    && (project->quests->is_act_disp == -1 ||
    project->quests->is_act_disp == 1)) {
        project->quests->is_act_disp = 0;
        return;
    }
}

void quest_event(project_t *project, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA
    && (project->quests->is_act_disp == -1 ||
    project->quests->is_act_disp == 0)) {
        project->quests->is_act_disp = 1;
        return;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA
    && project->quests->is_act_disp == 1) {
        project->quests->is_act_disp = -1;
        return;
    }
    quest_event_bis(project, event);
}
