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
    int player_second_state;
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
    sfMusic *music_ingame;
    sfSound *sound;
    sfSoundBuffer *soundbuffer;
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
    int is_sliding;
    sfText *act_volume;
    slider_t *slider;
    button_t *fullscreen;
    button_t *windowed;
    button_t *first_resolution;
    button_t *second_resolution;
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
main_menu_t *init_main_menu_bis(project_t *project, main_menu_t *main_menu);
main_menu_t *init_main_menu_ter(main_menu_t *main_menu);
slider_t *create_slider(sfVector2f pos, sfVector2f size, sfColor background);
void next_init_main_menu(main_menu_t *main_menu);
void slider_event(project_t *project, sfEvent event);
void display_settings_pause(project_t *project);
void update_slider(project_t *project, slider_t *slider);
void update_settings(project_t *project);
void update_settings_pause(project_t *project);
void slider_event_pause(project_t *project, sfEvent event);
void destroy_main_menu(main_menu_t *menu);
void destroy_pause_menu(pause_menu_t *menu);

#endif
