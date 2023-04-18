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
        add_elem(project->inventory->bag, "assets/object/apple.png", OTHER, 1);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyB)
        add_elem(project->inventory->bag, "assets/object/strawberry.png",
        OTHER, 1);
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

void check_all_pnj_dialogue(project_t *project)
{
    list_t *temp_pnj = project->scene->pnj;
    all_pnjs_t *act_pnj;

    while (temp_pnj != NULL) {
        act_pnj = (all_pnjs_t *) temp_pnj->element;
        if (act_pnj->can_talk) {
            project->actual_dial->dialogue =
            get_dialogue_by_id(project, project->all_dialogues, act_pnj->dial);
            display_dialogue(project);
            break;
        }
        temp_pnj = temp_pnj->next;
    }
}

void new_save(project_t *project)
{
    int fd = open("save", O_WRONLY | O_CREAT, 0644);
    char *scene_id = my_put_nbr(project->scene_id);
    char *posx = my_put_nbr(project->player->pos.x);
    char *posy = my_put_nbr(project->player->pos.y);
    char *player_state = my_put_nbr(project->player->player_progress_state);

    write(fd, my_strcat(scene_id, "\n"), my_strlen(scene_id) + 1);
    write(fd, my_strcat(posx, " "), my_strlen(posx) + 1);
    write(fd, my_strcat(posy, "\n"), my_strlen(posy) + 1);
    write(fd, my_strcat(player_state, "\n"), my_strlen(player_state) + 1);
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
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace &&
        !project->inventory->is_active)
            check_all_pnj_dialogue(project);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyTab &&
        !project->actual_dial->is_displayed)
            switch_state_inventory(project->inventory);
        inventory_event(project, event);
        quest_event(project, event);
    }
}
