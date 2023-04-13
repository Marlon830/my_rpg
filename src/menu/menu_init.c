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
    main_menu->play = create_button((sfVector2f){750, 400},
    (sfVector2f){400, 150}, "PLAY", &play_button);
    main_menu->quit = create_button((sfVector2f){750, 600},
    (sfVector2f){400, 150}, "QUIT", &quit_button);

    return main_menu;
}
