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

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) {
        i = i + 1;
        if (s1[i] == '\0' && s2[i] == '\0') {
            return 0;
        }
    }
    return s1[i] - s2[i];
}

char *my_strcat(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    int curr1 = 0;
    int curr2 = 0;
    char *res = malloc(sizeof(char) * (len1 + len2 + 1));

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

char *int_to_string(int num)
{
    int num_copy = num;
    int len = 0;
    char *str;

    while (num_copy != 0) {
        len++;
        num_copy /= 10;
    }
    if (num == 0) len = 1;
    str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    for (int i = len - 1; i >= 0; i--) {
        str[i] = (num % 10) + '0';
        num /= 10;
    }
    return str;
}

sfVector2f convert_mouse_window(sfRenderWindow *window, int x, int y)
{
    sfView *view = sfView_create();
    sfVector2f pos;

    sfView_setSize(view, (sfVector2f) {1920, 1080});
    sfView_setCenter(view, (sfVector2f) {1920 / 2, 1080 / 2});
    if (window == NULL)
        return (sfVector2f) {x, y};
    pos = sfRenderWindow_mapPixelToCoords(window, (sfVector2i)
    {x, y}, view);
    return pos;
}
