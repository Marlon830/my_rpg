/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** credit.h
*/

#ifndef CREDIT_H_
    #define CREDIT_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <stdbool.h>

typedef struct credit_s {
    sfClock *clock_credit;
    sfTime time_credit;
    float seconds_credit;
    char *string;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfMusic *music;
    float volume;
} credit_t;

credit_t *create_credit(void);
void update_credit(project_t *project, credit_t *credit);
void credit_event(project_t *project);
void start_credit(project_t *project);
void destroy_credit(credit_t *credit);

#endif
