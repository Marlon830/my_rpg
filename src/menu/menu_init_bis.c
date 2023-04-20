/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu_init_bis.c
*/

#include "project.h"

pause_menu_t *init_pause_menu_bis(pause_menu_t *pause_menu)
{
    pause_menu->back_menu = create_button((sfVector2f){425, 800},
    (sfVector2f){420, 120}, "assets/UI/back_menu/", &back_menu_button);
    pause_menu->act_volume = create_text((sfVector2f) {1025, 400},
    (sfVector2f) {1, 1}, sfWhite);
    pause_menu->slider = create_slider((sfVector2f) {1100, 420},
    (sfVector2f) {300, 5}, sfBlack);
    pause_menu->fullscreen = create_button((sfVector2f){1025, 550},
    (sfVector2f) {420 / 2, 120 / 2}, "assets/UI/fullscreen/",
    &set_win_fullscreen);
    pause_menu->windowed = create_button((sfVector2f)
    {1025 + (420 / 2) + 5, 550},
    (sfVector2f) {420 / 2, 120 / 2}, "assets/UI/windowed/", &set_win_windowed);
    pause_menu->first_resolution = create_button((sfVector2f){1025, 700},
    (sfVector2f) {420 / 2, 120 / 2}, "assets/UI/resolution1/",
    &set_first_resolution);
    pause_menu->second_resolution = create_button((sfVector2f)
    {1025 + (420 / 2) + 5, 700},
    (sfVector2f) {420 / 2, 120 / 2}, "assets/UI/resolution2/",
    &set_second_resolution);
    return pause_menu;
}

pause_menu_t *init_pause_menu(project_t *project)
{
    pause_menu_t *pause_menu = malloc(sizeof(pause_menu_t));

    pause_menu->camera = sfView_create();
    change_view(project, pause_menu->camera, (sfVector2f){1920, 1080},
    (sfVector2f){1920 / 2, 1080 / 2});
    pause_menu->background = create_image((sfVector2f){0, 0},
    "background.png", (sfIntRect){0, 0, 1920, 1080},
    (sfVector2f){1920, 1080});
    pause_menu->background->nb_sprite = 1;
    pause_menu->state = NAUNE;
    pause_menu->resume = create_button((sfVector2f){425, 350},
    (sfVector2f){420, 120}, "assets/UI/continue/", &resume_button);
    pause_menu->save = create_button((sfVector2f){425, 500},
    (sfVector2f){420, 120}, "assets/UI/save/", &new_save);
    pause_menu->settings = create_button((sfVector2f){425, 650},
    (sfVector2f){420, 120}, "assets/UI/settings/", &display_settings_pause);
    pause_menu->is_sliding = 0;
    return init_pause_menu_bis(pause_menu);
}

main_menu_t *init_main_menu(project_t *project)
{
    main_menu_t *main_menu = malloc(sizeof(main_menu_t));
    main_menu->camera = sfView_create();
    change_view(project, main_menu->camera, (sfVector2f){1920, 1080},
    (sfVector2f){1920 / 2, 1080 / 2});
    main_menu->background = create_image((sfVector2f){0, 0},
    "background.png", (sfIntRect){0, 0, 1920, 1080},
    (sfVector2f){1920, 1080});
    main_menu->background->nb_sprite = 1;
    main_menu->state = NAUNE;
    return init_main_menu_bis(project, main_menu);
}
