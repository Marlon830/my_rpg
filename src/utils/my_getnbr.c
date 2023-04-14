/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_getnbr.c
*/

int my_getnbr(char *str)
{
    int i = 0;
    int res = 0;
    int neg = 1;

    while (str[i] == '-' || str[i] == '+') {
        neg *= (str[i] == '-') ? -1 : 1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return res * neg;
}
