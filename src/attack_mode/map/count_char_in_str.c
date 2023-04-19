/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** count_char_in_str.c
*/

#include "attack_mode.h"

int count_char_in_str(char *str, char c)
{
    int i = 0;
    int res = 0;

    while (str[i]) {
        res += (str[i] == c);
        i++;
    }
    return res;
}
