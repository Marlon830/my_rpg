/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** utils.h
*/

#ifndef UTILS_H_
    #define UTILS_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <string.h>
    #include <unistd.h>

typedef struct sprite_s sprite_t;

enum type {
    IMAGE,
    COLLIDER,
    TP,
    SCENE
};

typedef struct list_s {
    void *element;
    char *id;
    enum type type;
    struct list_s *next;
} list_t;

void delete(list_t **list, const char *id);
void *get_item(list_t *list, char *id);
char *my_strcat(char *str, char *str2);
int my_strlen(char *str);
int my_strcmp(char *s1,  char *s2);
int my_getnbr(char *str);
void my_strcpy(char *dest, char *src);
void push_back(list_t **list, char *id, void *node, enum type type);

#endif
