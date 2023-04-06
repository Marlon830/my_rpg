/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** string.c
*/

#include "../../include/project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *str)
{
    int i = 0;
    if (str == NULL)
        return 0;
    for (; str[i]; i++);
    return i;
}

int my_strcmp(char *s1,  char *s2)
{
    for (int i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    if (my_strlen(s1) <= my_strlen(s2))
        return 0;
    return my_strlen(s1) - my_strlen(s2);
}

char *cat(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    int curr1 = 0;
    int curr2 = 0;
    char *res = malloc(len1 + len2 + 1);

    for (int i = 0; i != (len1 + len2); i++) {
        if (curr1 != len1) {
            res[i] = s1[curr1];
            curr1++;
        } else {
            res[i] = s2[curr2];
            curr2++;
        }
    }
    res[len1 + len2] = '\0';
    return res;
}

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
