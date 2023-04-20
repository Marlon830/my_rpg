/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_manager5.c
*/

#include "project.h"

char *get_box_path(box_t *box)
{
    char *path;

    if (box->name == NULL)
        return NULL;
    path = malloc(my_strlen(box->name) + 8);
    my_strcpy(path, "assets/player_");
    my_strcpy(path + my_strlen(path), box->name +
    get_good_path(box->name));
    return path;
}

void switch_stat(project_t *project, box_t *box, box_t *box2)
{
    if (box->type_box == OTHER && box2->type_box == OTHER)
        return;
    if (box->type_box != OTHER)
        remove_stat(project->player, get_box_path(box));
    if (box2->type_box != OTHER)
        remove_stat(project->player, get_box_path(box2));
    if (box->type_box == OTHER)
        add_stat(project->player, get_box_path(box));
    if (box2->type_box == OTHER)
        add_stat(project->player, get_box_path(box2));
}

void add_or_delete_stat(project_t *project, box_t *new_box, box_t *selected_box)
{
    if (new_box->type_box == selected_box->type_box)
        return;
    if (new_box->type_box != OTHER)
        add_stat(project->player, get_box_path(selected_box));
    if (new_box->type_box == OTHER)
        remove_stat(project->player, get_box_path(selected_box));
}
