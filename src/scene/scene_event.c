/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** scene_event.c
*/

#include "project.h"

void inventory_event3(project_t *project, sfEvent event)
{
    if (project->inventory->is_active && event.type == sfEvtMouseButtonPressed
    && event.mouseButton.button == sfMouseLeft)
        select_box(project, (sfVector2f) {event.mouseButton.x,
        event.mouseButton.y});
    if (project->inventory->is_active && event.type == sfEvtMouseButtonReleased
    && event.mouseButton.button == sfMouseLeft && project->inventory->state ==
    PRESSED)
        unselect_box(project, (sfVector2f) {event.mouseButton.x,
        event.mouseButton.y});
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyU)
        add_elem(project->inventory->bag, "assets/object/helmet_gold.png",
        HELMET, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
        add_elem(project->inventory->bag, "assets/object/boots_gold.png",
        BOOTS, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLShift)
        project->inventory->shift_pressed = true;
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyLShift)
        project->inventory->shift_pressed = false;
}

void inventory_event2(project_t *project, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI)
        add_elem(project->inventory->bag, "assets/object/armor_gold.png",
        ARMOR, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyK)
        add_elem(project->inventory->bag, "assets/object/ring_gelano.png",
        RING, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyO)
        add_elem(project->inventory->bag, "assets/object/pants_gold.png",
        PANTS, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM)
        add_elem(project->inventory->bag, "assets/object/shield_gold.png",
        SHIELD, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyJ)
        add_elem(project->inventory->bag, "assets/object/amulet_emerald.png",
        AMULET, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyC)
        delete_elem(project->inventory->bag, "assets/object/apple.png", 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE)
        delete_elem(project->inventory->bag, "assets/object/strawberry.png",
        1);
}

void inventory_event(project_t *project, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
        add_elem(project->inventory->bag, "assets/object/apple.png", OTHER, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyB)
        add_elem(project->inventory->bag, "assets/object/strawberry.png",
        OTHER, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
        add_elem(project->inventory->bag, "assets/object/sword_silver.png",
        SWORD, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL)
        add_elem(project->inventory->bag, "assets/object/sword_gold.png",
        SWORD, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyJ)
        add_elem(project->inventory->bag, "assets/object/amulet_ruby.png",
        AMULET, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyJ)
        add_elem(project->inventory->bag, "assets/object/amulet_diamond.png",
        AMULET, 1);
    inventory_event2(project, event);
    inventory_event3(project, event);
}

void scene_event_bis(project_t *project, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && (event.key.code == sfKeySpace ||
    event.key.code == sfKeyE) &&
    !project->inventory->is_active)
        check_all_pnj_dialogue(project);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyTab &&
    !project->actual_dial->is_displayed) {
        play_sound(project, "assets/music/inventory.ogg");
        switch_state_inventory(project->inventory);
    }
}

void scene_event(project_t *project)
{
    sfEvent event;

    set_all_pnj_dialogues(project);
    while (sfRenderWindow_pollEvent(project->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(project->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            project->status = PAUSE_MENU;
            sfRenderWindow_setView(project->window,
            project->pause_menu->camera);
        }
        scene_event_bis(project, event);
        inventory_event(project, event);
        quest_event(project, event);
    }
}
