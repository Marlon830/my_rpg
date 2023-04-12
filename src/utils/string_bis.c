/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** string_bis.c
*/

#include "../../include/project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_num(char c)
{
    return (c >= '0' && c <= '9');
}

int my_getnbr(char *str)
{
    int number = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '-') {
        sign = -1;
        i++;
    }

    while (!is_num(str[i]) && str[i] != '\0') {
        i++;
    }

    while (is_num(str[i])) {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    return sign * number;
}

void my_strcpy(char *dest, char *src)
{
    int src_len = my_strlen(src);

    for (int i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[src_len] = '\0';
}
