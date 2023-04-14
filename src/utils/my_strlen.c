/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}
