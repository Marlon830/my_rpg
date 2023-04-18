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

enum main_menu_state {
    NAUNE,
    PLAY,
    SETTINGS
};

typedef struct save_s {
    int scene_id;
    sfVector2f pos;
    int player_state;
} save_t;

typedef struct main_menu_s {
    image_t *background;
    button_t *play;
    button_t *settings;
    button_t *quit;
    button_t *new_game;
    button_t *load_game;
    sfView *camera;
    save_t *save;
    enum main_menu_state state;
} main_menu_t;

typedef struct pause_menu_s {
    image_t *background;
    button_t *resume;
    button_t *save;
    button_t *settings;
    button_t *back_menu;
    sfView *camera;
    enum main_menu_state state;
} pause_menu_t;

void main_menu_event(project_t *project);
main_menu_t *init_main_menu(project_t *project);
pause_menu_t *init_pause_menu(project_t *project);
void draw_main_menu(project_t *project);
void new_game_button(project_t *project);
void quit_button(project_t *project);
void display_play(project_t *project);
void display_settings(project_t *project);
void load_game_button(project_t *project);
void resume_button(project_t *project);
void pause_menu_event(project_t *project);
void draw_pause_menu(project_t *project);
void back_menu_button(project_t *project);

#endif
