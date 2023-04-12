/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** scene_event.c
*/

#include "../../include/project.h"

void scene_event(project_t *project)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(project->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(project->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(project->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
            project->actual_dial->dialogue =
            get_dialogue_by_id(project, project->all_dialogues, "LeFlopeux02");
            display_dialogue(project);
        }
    }
}
