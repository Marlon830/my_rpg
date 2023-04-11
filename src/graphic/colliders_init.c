/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** colliders_init.c
*/

#include "../../include/graphic.h"
#include "../../include/utils.h"
#include <string.h>

void get_collider_coord(char *line, graphic_t *scene)
{
    char *num1 = malloc(sizeof(line)); 
    char *num2 = malloc(sizeof(line)); 
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;

    for (; line[i] != ' '; i++)
        num1[i] = line[i];
    num1[i] = '\0';
    x = my_getnbr(num1);
    for (; line[i + j + 1]; j++)
        num2[j] = line[i + j + 1];
    num2[j] = '\0';
    y = my_getnbr(num2);
    push_back(&scene->colliders, "collider",
    create_collider(x, y, 16, 16), COLLIDER);
}


void colliders_init(char *path, graphic_t *scene)
{
    FILE *fp = fopen(path, "r");
    ssize_t read;
    size_t len = 0;
    char *line = NULL;

    while ((read = getline(&line, &len, fp)) != -1)
        get_collider_coord(line, scene);
}
