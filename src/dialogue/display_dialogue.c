/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_dialogue.c
*/

#include "project.h"

int display_dialogue_bis(char *dialogue, int act_pos, project_t *project,
    all_pnjs_t *act_pnj)
{
    int i = act_pos;

    if (dialogue[i] == '#') {
        project->actual_dial->text = create_text((sfVector2f){160, 160},
        (sfVector2f){0.2, 0.2}, sfWhite);
        project->actual_dial->pos = 0;
        project->actual_dial->is_displayed = 0;
        change_state_with_dialogue(project, act_pnj);
        return -84;
    }
    if (i == 0) {
        for (; dialogue[i] != '#'; i++);
        i += 2;
    }
    return i;
}

void display_dialogue(project_t *project, all_pnjs_t *act_pnj)
{
    char *dialogue = project->actual_dial->dialogue;
    int i = project->actual_dial->pos;
    char *ans = malloc(sizeof(char) * (my_strlen(dialogue) + 1));
    int j = 0;

    i = display_dialogue_bis(dialogue, i, project, act_pnj);
    if (i == -84)
        return;
    while (dialogue[i] != '-') {
        ans[j] = dialogue[i];
        i++;
        j++;
    }
    if (dialogue[i] == '-')
        i += 2;
    ans[j] = '\0';
    project->actual_dial->pos = i;
    sfText_setString(project->actual_dial->text, ans);
    project->actual_dial->is_displayed = 1;
}
