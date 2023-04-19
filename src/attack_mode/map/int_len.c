/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** int_len.c
*/

#include "attack_mode.h"

int int_len(int x)
{
    int len = 0;
    int tmp = x;

    if (x == 0)
        return 1;
    while (tmp) {
        tmp /= 10;
        len++;
    }
    if (len == 0)
        len = 1;
    return len;
}
