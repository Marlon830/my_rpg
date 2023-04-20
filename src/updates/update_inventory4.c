/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_inventory4.c
*/

#include "project.h"

void update_equipment3_bis(project_t *project, list_box_t *temp, char *path,
int count)
{
    if (count == 5 && temp->box->sprite != NULL)
        modify_amulet(project->player, path);
    if (count == 5 && temp->box->sprite == NULL &&
    project->player->equipment->amulet != NULL)
        modify_amulet(project->player, NULL);
    if (count == 6 && temp->box->sprite != NULL)
        modify_ring(project->player, path);
    if (count == 6 && temp->box->sprite == NULL &&
    project->player->equipment->ring != NULL)
        modify_ring(project->player, NULL);
    if (count == 7 && temp->box->sprite != NULL)
        modify_sword(project->player, path);
    if (count == 7 && temp->box->sprite == NULL &&
    project->player->equipment->sword != NULL)
        modify_sword(project->player, NULL);
    if (count == 8 && temp->box->sprite != NULL)
        modify_shield(project->player, path);
    if (count == 8 && temp->box->sprite == NULL &&
    project->player->equipment->shield != NULL)
        modify_shield(project->player, NULL);
}

void update_equipment3(project_t *project, list_box_t *temp, char *path,
int count)
{
    while (temp != NULL) {
        if (temp->box->sprite != NULL) {
            path = malloc(my_strlen(temp->box->name) + 8);
            my_strcpy(path, "assets/player_");
            my_strcpy(path + my_strlen(path), temp->box->name +
            get_good_path(temp->box->name));
        }
        update_equipment3_bis(project, temp, path, count);
        count++;
        temp = temp->next;
    }
}

void update_equipment2_bis(project_t *project, list_box_t *temp, char *path,
int count)
{
    if (count == 1 && temp->box->sprite != NULL)
        modify_helmet(project->player, path);
    if (count == 1 && temp->box->sprite == NULL &&
        project->player->equipment->helmet != NULL)
        modify_helmet(project->player, NULL);
    if (count == 2 && temp->box->sprite != NULL)
        modify_armor(project->player, path);
    if (count == 2 && temp->box->sprite == NULL &&
        project->player->equipment->armor != NULL)
        modify_armor(project->player, NULL);
    if (count == 3 && temp->box->sprite != NULL)
        modify_pants(project->player, path);
    if (count == 3 && temp->box->sprite == NULL &&
        project->player->equipment->pants != NULL)
        modify_pants(project->player, NULL);
    if (count == 4 && temp->box->sprite != NULL)
        modify_boots(project->player, path);
    if (count == 4 && temp->box->sprite == NULL &&
        project->player->equipment->boots != NULL)
        modify_boots(project->player, NULL);
}

int update_equipment2(project_t *project, list_box_t *temp, char *path)
{
    int count = 1;

    while (temp != NULL) {
        if (temp->box->sprite != NULL) {
            path = malloc(my_strlen(temp->box->name) + 8);
            my_strcpy(path, "assets/player_");
            my_strcpy(path + my_strlen(path), temp->box->name +
            get_good_path(temp->box->name));
        }
        update_equipment2_bis(project, temp, path, count);
        count++;
        temp = temp->next;
    }
    return count;
}

void update_equipment(project_t *project, inventory_t *inventory)
{
    list_box_t *temp = inventory->first_equipment;
    char *path = NULL;
    int count = update_equipment2(project, temp, path);

    temp = inventory->second_equipment;
    update_equipment3(project, temp, path, count);
}
