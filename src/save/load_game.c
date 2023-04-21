/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load_game.c
*/

#include "project.h"

void get_inventory3(project_t *project, FILE *fp)
{
    list_box_t *temp = project->inventory->bag;
    size_t len = 0;
    char *line = NULL;
    char *name;
    int type;
    int quantity;

    while (temp != NULL) {
        getline(&line, &len, fp);
        if (line[0] != '0') {
            name = get_info(line, 1);
            quantity = my_getnbr(get_info(line, 2));
            type = my_getnbr(get_info(line, 3));
            add_new_elem_in_box(temp->box, name, type, quantity);
        }
        temp = temp->next;
    }
    get_quests(project, fp);
}

void get_inventory2(project_t *project, FILE *fp)
{
    list_box_t *temp = project->inventory->second_equipment;
    size_t len = 0;
    char *line = NULL;
    char *name;
    int type;
    int quantity;

    while (temp != NULL) {
        getline(&line, &len, fp);
        if (line[0] != '0') {
            name = get_info(line, 1);
            quantity = my_getnbr(get_info(line, 2));
            type = my_getnbr(get_info(line, 3));
            add_new_elem_in_box(temp->box, name, type, quantity);
            add_stat(project->player, temp->box->name);
        }
        temp = temp->next;
    }
}

void get_inventory(project_t *project, FILE *fp)
{
    list_box_t *temp = project->inventory->first_equipment;
    size_t len = 0;
    char *line = NULL;
    char *name;
    int type;
    int quantity;
    while (temp != NULL) {
        getline(&line, &len, fp);
        if (line[0] != '0') {
            name = get_info(line, 1);
            quantity = my_getnbr(get_info(line, 2));
            type = my_getnbr(get_info(line, 3));
            add_new_elem_in_box(temp->box, name, type, quantity);
            add_stat(project->player, temp->box->name);
        }
        temp = temp->next;
    }
    get_inventory2(project, fp);
    get_inventory3(project, fp);
    update_equipment(project, project->inventory);
}

void get_save_bis(save_t *save, char *line, size_t len, FILE *fp)
{
    getline(&line, &len, fp);
    save->player_state = my_getnbr(line);
    getline(&line, &len, fp);
    save->player_second_state = my_getnbr(line);
}

save_t *get_save(project_t *project)
{
    save_t *save = malloc(sizeof(save_t));
    FILE *fp = fopen("save", "r");
    size_t len = 0;
    char *line = NULL;

    save->pos = (sfVector2f){0, 0};
    getline(&line, &len, fp);
    if (line[0] == 'R') {
        free(save);
        return NULL;
    }
    save->scene_id = my_getnbr(line);
    getline(&line, &len, fp);
    save->pos.x = my_getnbr(line);
    for (; line[0] != ' '; line++);
    save->pos.y = my_getnbr(line);
    get_save_bis(save, line, len, fp);
    get_inventory(project, fp);
    return save;
}
