/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_str_until.c
*/

#include "attack_mode.h"

char *get_str_until(char *str, char sep)
{
    int i = 0;
    while (str[i] != sep && str[i]) {
        i++;
    }
    char *res = malloc(sizeof(char) * (i + 1));
    res[i] = 0;
    for (int l = 0; l < i; l++) {
        res[l] = str[l];
    }
    return res;
}
