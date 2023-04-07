/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** colliders_init.c
*/

#include "../../include/graphic.h"
#include "../../include/utils.h"
#include <string.h>

void colliders_init(char *path, graphic_t *graphic)
{
    FILE *fp = fopen(path, "r");
    ssize_t read;
    size_t len = 0;
    char *line = NULL;
    char *num = NULL;
    int y = 0;
    int x = 0;

    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1) {
        num = strtok(line, " ");
        x = my_getnbr(num);
        num = strtok(NULL, " ");
        y = my_getnbr(num);
        push_back(&graphic->colliders, "collider",
        create_collider(x, y, 16, 16), COLLIDER);
    }
}