/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** save_game.c
*/

#include "project.h"

void save_left_equipment(project_t *project, int fd)
{
    list_box_t *tmp = project->inventory->first_equipment;
    char *quantity;

    while (tmp != NULL) {
        if (tmp->box->sprite != NULL) {
            write(fd, tmp->box->name, my_strlen(tmp->box->name));
            quantity = int_to_str(tmp->box->quantity);
            write(fd, " ", 1);
            write(fd, quantity, my_strlen(quantity));
            write(fd, " ", 1);
            write(fd, int_to_str(tmp->box->type_sprite), 1);
            write(fd, "\n", 1);
        }
        if (tmp->box->sprite == NULL)
            write(fd, "0\n", 2);
        tmp = tmp->next;
    }
}

void save_right_equipment(project_t *project, int fd)
{
    list_box_t *tmp = project->inventory->second_equipment;
    char *quantity;

    while (tmp != NULL) {
        if (tmp->box->sprite != NULL) {
            write(fd, tmp->box->name, my_strlen(tmp->box->name));
            quantity = int_to_str(tmp->box->quantity);
            write(fd, " ", 1);
            write(fd, quantity, my_strlen(quantity));
            write(fd, " ", 1);
            write(fd, int_to_str(tmp->box->type_sprite), 1);
            write(fd, "\n", 1);
        }
        if (tmp->box->sprite == NULL)
            write(fd, "0\n", 2);
        tmp = tmp->next;
    }
}

void save_bag(project_t *project, int fd)
{
    list_box_t *tmp = project->inventory->bag;
    char *quantity;

    while (tmp != NULL) {
        if (tmp->box->sprite != NULL) {
            write(fd, tmp->box->name, my_strlen(tmp->box->name));
            quantity = int_to_str(tmp->box->quantity);
            write(fd, " ", 1);
            write(fd, quantity, my_strlen(quantity));
            write(fd, " ", 1);
            write(fd, int_to_str(tmp->box->type_sprite), 1);
            write(fd, "\n", 1);
        }
        if (tmp->box->sprite == NULL)
            write(fd, "0\n", 2);
        tmp = tmp->next;
    }
}

void new_save(project_t *project)
{
    int fd = open("save", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char *scene_id = my_put_nbr(project->scene_id);
    char *posx = my_put_nbr(project->player->pos.x);
    char *posy = my_put_nbr(project->player->pos.y);
    char *player_state = my_put_nbr(project->player->player_progress_state);
    char *player_state_second = my_put_nbr(
    project->player->player_second_state);

    write(fd, my_strcat(scene_id, "\n"), my_strlen(scene_id) + 1);
    write(fd, my_strcat(posx, " "), my_strlen(posx) + 1);
    write(fd, my_strcat(posy, "\n"), my_strlen(posy) + 1);
    write(fd, my_strcat(player_state, "\n"), my_strlen(player_state) + 1);
    write(fd, my_strcat(player_state_second, "\n"),
    my_strlen(player_state_second) + 1);
    save_left_equipment(project, fd);
    save_right_equipment(project, fd);
    save_bag(project, fd);
    save_quests(project, fd);
    close(fd);
}
