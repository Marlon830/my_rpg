/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** load_game_bis.c
*/

#include "project.h"

char *get_info(char *str, int pos_word)
{
    int pos = 0;
    char *new_str = malloc(my_strlen(str));
    int new_pos = 0;

    for (int i = 0; i < pos_word - 1; i++) {
        while (str[pos] != ' ')
            pos++;
        pos++;
    }
    while (str[pos] != ' ' && str[pos] != '\n') {
        new_str[new_pos] = str[pos];
        pos++;
        new_pos++;
    }
    new_str[new_pos] = '\0';
    return new_str;
}
