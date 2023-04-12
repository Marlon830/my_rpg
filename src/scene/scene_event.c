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
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyTab)
            switch_state_inventory(project->inventory);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
            add_elem(project->inventory->bag, "assets/object/apple.png", 1);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyB)
            add_elem(project->inventory->bag, "assets/object/strawberry.png",
            1);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyC)
            delete_elem(project->inventory->bag, "assets/object/apple.png", 1);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE)
            delete_elem(project->inventory->bag, "assets/object/strawberry.png",
            1);
    }
}
