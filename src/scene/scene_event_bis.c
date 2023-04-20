/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** scene_event_bis.c
*/

#include "project.h"

void check_all_pnj_dialogue(project_t *project)
{
    list_t *temp_pnj = project->scene->pnj;
    all_pnjs_t *act_pnj;

    while (temp_pnj != NULL) {
        act_pnj = (all_pnjs_t *) temp_pnj->element;
        if (act_pnj->can_talk) {
            play_sound(project, "assets/music/dialogue_sound.ogg");
            project->actual_dial->dialogue =
            get_dialogue_by_id(project, project->all_dialogues, act_pnj->dial);
            display_dialogue(project, act_pnj);
            break;
        }
        temp_pnj = temp_pnj->next;
    }
}
