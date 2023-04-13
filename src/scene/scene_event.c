/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** scene_event.c
*/

#include "project.h"

void inventory_event(project_t *project, sfEvent event)
{
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
    if (project->inventory->is_active && event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseLeft)
        select_box(project, (sfVector2f) {event.mouseButton.x,
        event.mouseButton.y});
    if (project->inventory->is_active && event.type == sfEvtMouseButtonReleased
    && event.mouseButton.button == sfMouseLeft)
        unselect_box(project, (sfVector2f) {event.mouseButton.x,
        event.mouseButton.y});
}

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
            get_dialogue_by_id(project, project->all_dialogues, "Theoronfle");
            display_dialogue(project);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyTab)
            switch_state_inventory(project->inventory);
        inventory_event(project, event);
    }
}
