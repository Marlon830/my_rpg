/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_dialogue.c
*/

#include "project.h"

char *get_type(char *str)
{
    char *type = malloc(sizeof(char) * my_strlen(str));
    int i = 0;

    for (; str[i] != ':'; i++)
        type[i] = str[i];
    type[i] = '\0';
    return type;
}

char *get_png_file(char *path_to_dialogue)
{
    int fd = open(path_to_dialogue, O_RDONLY);
    struct stat sb;
    char *buffer;

    stat(path_to_dialogue, &sb);
    buffer = malloc(sizeof(char) * sb.st_size + 1);
    read(fd, buffer, sb.st_size);
    return buffer;
}

void create_all_dialogue(char *path_to_all_dialogue)
{

}
