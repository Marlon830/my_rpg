/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** int_to_str.c
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
