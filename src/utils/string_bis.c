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

int my_intlen(int nb)
{
    int i = 0;

    if (nb == 0)
        return 1;
    while (nb > 0) {
        nb /= 10;
        i++;
    }
    return i;
}

char *my_put_nbr(int nb)
{
    int j = my_intlen(nb);
    char *str = malloc(sizeof(char) * (j + 1));

    for (int i = j - 1; i >= 0; i--) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }

    str[j] = '\0';
    return str;
}
