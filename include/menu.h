/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu.h
*/

#ifndef MENU_H_
    #define MENU_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include "utils.h"

typedef struct project_s project_t;
typedef struct image_s image_t;

typedef struct main_menu_s {
    image_t *background;
    button_t *play;
    button_t *quit;
    sfText *test;
    sfView *camera;
} main_menu_t;

void menu_event(project_t *project);
main_menu_t *init_main_menu(project_t *project);
void draw_main_menu(project_t *project);
void play_button(project_t *project);
void quit_button(project_t *project);

#endif