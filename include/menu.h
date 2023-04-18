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

typedef struct slider_s {
    sfRectangleShape *rect;
    sfCircleShape *circle;
    sfColor background;
    sfColor foreground;
    sfVector2f position;
    sfVector2f position_circle;
    sfVector2f size;
    sfVector2f circle_size;
    float value;
} slider_t;

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
    button_t *fullscreen;
    button_t *windowed;
    button_t *first_resolution;
    button_t *second_resolution;
    sfText *act_volume;
    sfView *camera;
    sfMusic *music;
    sfSound *sound;
    slider_t *slider;
    int is_sliding;
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
void set_win_fullscreen(project_t *project);
void set_win_windowed(project_t *project);
void set_first_resolution(project_t *project);
void set_second_resolution(project_t *project);
void load_game_button(project_t *project);
void resume_button(project_t *project);
void pause_menu_event(project_t *project);
void draw_pause_menu(project_t *project);
void back_menu_button(project_t *project);
void button_click(button_t *button, project_t *project, sfEvent event);

#endif
