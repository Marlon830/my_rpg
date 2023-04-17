/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu_init.c
*/

#include "project.h"


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
    main_menu->play = create_button((sfVector2f){425, 400},
    (sfVector2f){420, 120}, "assets/UI/play/", &display_play);
    main_menu->settings = create_button((sfVector2f){425, 550},
    (sfVector2f){420, 120}, "assets/UI/settings/", &display_settings);
    main_menu->quit = create_button((sfVector2f){425, 700},
    (sfVector2f){420, 120}, "assets/UI/quit/", &quit_button);
    main_menu->new_game = create_button((sfVector2f){1025, 400},
    (sfVector2f){420, 120}, "assets/UI/new_game/", &play_button);
    main_menu->load_game = create_button((sfVector2f){1025, 550},
    (sfVector2f){420, 120}, "assets/UI/load_game/", &play_button);
    return main_menu;
}
