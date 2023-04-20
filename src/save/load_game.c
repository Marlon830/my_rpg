/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load_game.c
*/

#include "project.h"

char *get_info(char *str, int pos_word)
{
    int pos = 0;
    char *new_str = malloc(my_strlen(str));
    int new_pos = 0;

    for (int i = 0; i < pos_word - 1; i++) {
        while (str[pos] != ' ')
            pos++;
        pos++;
    }
    while (str[pos] != ' ' && str[pos] != '\n') {
        new_str[new_pos] = str[pos];
        pos++;
        new_pos++;
    }
    new_str[new_pos] = '\0';
    return new_str;
}

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
        }
        temp = temp->next;
    }
    get_inventory2(project, fp);
    get_inventory3(project, fp);
    update_equipment(project, project->inventory);
}

save_t *get_save(project_t *project)
{
    save_t *save = malloc(sizeof(save_t));
    save->pos = (sfVector2f){0, 0};
    FILE *fp = fopen("save", "r");
    size_t len = 0;
    char *line = NULL;
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
    getline(&line, &len, fp);
    save->player_state = my_getnbr(line);
    get_inventory(project, fp);
    fclose(fp);
    return save;
}
