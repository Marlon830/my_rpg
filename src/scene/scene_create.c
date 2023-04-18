/*
** EPITECH PROJECT, 2022
** tiled-to-c
** File description:
** scene_create.c
*/

#include "scene.h"
#include "utils.h"
#include "project.h"
#include <string.h>

void get_tp_map(map_t *map, char *line)
{
    sfVector2f pos = (sfVector2f){0, 0};
    sfVector2f tp_pos = (sfVector2f){0, 0};
    int to_scene_id = 0;

    pos.x = my_getnbr(line);
    for (; line[0] != ' '; line++);
    pos.y = my_getnbr(line += 1);
    for (; line[0] != ' '; line++);
    to_scene_id = my_getnbr(line += 1);
    for (; line[0] != ' '; line++);
    tp_pos.x = my_getnbr(line += 1);
    for (; line[0] != ' '; line++);
    tp_pos.y = my_getnbr(line += 1);
    tp_t *tp = create_tp(pos, tp_pos, to_scene_id);
    push_back(&map->tp, "tp", tp, TP);
    map->nb_tp++;
}

char *get_pnj_name(char *line)
{
    int i = 0;
    char *name;

    for (; line[i] != ' '; i++);
    name = malloc(sizeof(char) * (my_strlen(line) + 1));
    my_strcpy(name, line);
    name[i] = '\0';
    return name;
}

void get_pnj_map(map_t *map, char *line)
{
    sfFloatRect *rect = malloc(sizeof(sfFloatRect));
    char *pnj_name;

    rect->left = my_getnbr(line);
    for (; line[0] != ' '; line++);
    rect->top = my_getnbr(line += 1);
    for (; line[0] != ' '; line++);
    pnj_name = get_pnj_name(line += 1);
    for (; line[0] != ' '; line++);
    rect->width = my_getnbr(line += 1);
    for (; line[0] != ' '; line++);
    rect->height = my_getnbr(line += 1);
    all_pnjs_t *pnj = create_pnj(NULL,
    rect, pnj_name);
    push_back(&map->pnj, pnj->name,
    (all_pnjs_t *) pnj, PNJ);
    map->nb_pnj++;
}

map_t *next_get_map(map_t *map, char *map_name)
{
    FILE *fp = fopen(my_strcat(my_strcat("./assets/", map_name),
    "/data.mp"), "r");
    ssize_t read;
    size_t len = 0;
    char *line = NULL;

    getline(&line, &len, fp);
    map->size.x = my_getnbr(line);
    for (; line[0] != ' '; line++);
    map->size.y = my_getnbr(line);
    while ((read = getline(&line, &len, fp)) != -1 && line[0] != '#')
        get_tp_map(map, line);
    if (line[0] != '#')
        return map;
    while ((read = getline(&line, &len, fp)) != -1)
        get_pnj_map(map, line);
    fclose(fp);
    return map;
}

map_t *get_map(char *map_name)
{
    map_t *map = malloc(sizeof(map_t));

    map->size = (sfVector2f){0, 0};
    map->name = map_name;
    map->tp = NULL;
    map->nb_tp = 0;
    map->nb_pnj = 0;
    map->pnj = NULL;
    return next_get_map(map, map_name);
}
