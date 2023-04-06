/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** save_map.c
*/

#include "attack_mode.h"

char *int_to_str(int x)
{
    int len = 0;
    int tmp = x;
    while (tmp) {
        tmp /= 10;
        len++;
    }
    if (len == 0)
        len = 1;
    char *res = malloc(sizeof(char) * (len + 1));
    res[len] = 0;
    for (int i = len - 1; i >= 0; i--) {
        res[i] = x % 10 + '0';
        x /= 10;
    }
    return res;
}

void write_val_map(int fd, int x, int y, map_t *map)
{
    char *x_str = int_to_str(x);
    char *y_str = int_to_str(y);
    char *z_str = int_to_str(map->tiles[x * map->height + y]->height);

    write(fd, x_str, my_strlen(x_str));
    write(fd, " ", 1);
    write(fd, y_str, my_strlen(y_str));
    write(fd, " ", 1);
    write(fd, z_str, my_strlen(z_str));
    write(fd, x == map->width - 1 && y == map->height - 1 ? " " : "\n", 1);
    free(x_str);
    free(y_str);
    free(z_str);
}

void save_map(map_t *map)
{
    int i = 0;
    int fd = open("map.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);

    write(fd, int_to_str(map->width), my_strlen(int_to_str(map->width)));
    write(fd, " ", 1);
    write(fd, int_to_str(map->height), my_strlen(int_to_str(map->height)));
    write(fd, "\n", 1);
    for (int x = 0; x < map->width; x++) {
        for (int y = map->height - 1; y >= 0; y--) {
            write_val_map(fd, x, y, map);
            i++;
        }
    }
    close(fd);
}
