/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_menu.c
*/

#include "project.h"

void destroy_main_menu2(main_menu_t *menu)
{
    if (menu->quit != NULL)
        destroy_button(menu->quit);
    if (menu->save != NULL)
        free(menu->save);
    if (menu->second_resolution != NULL)
        destroy_button(menu->second_resolution);
    if (menu->settings != NULL)
        destroy_button(menu->settings);
    if (menu->slider != NULL)
        destroy_slider(menu->slider);
    if (menu->windowed != NULL)
        destroy_button(menu->windowed);
    free(menu);
}

void destroy_main_menu(main_menu_t *menu)
{
    if (menu == NULL)
        return;
    if (menu->act_volume != NULL)
        sfText_destroy(menu->act_volume);
    if (menu->background != NULL)
        destroy_image(menu->background);
    if (menu->camera != NULL)
        sfView_destroy(menu->camera);
    if (menu->first_resolution != NULL)
        destroy_button(menu->first_resolution);
    if (menu->fullscreen != NULL)
        destroy_button(menu->fullscreen);
    if (menu->load_game != NULL)
        destroy_button(menu->load_game);
    if (menu->new_game != NULL)
        destroy_button(menu->new_game);
    if (menu->play != NULL)
        destroy_button(menu->play);
    destroy_main_menu2(menu);
}

void destroy_pause_menu2(pause_menu_t *menu)
{
    if (menu->second_resolution != NULL)
        destroy_button(menu->second_resolution);
    if (menu->settings != NULL)
        destroy_button(menu->settings);
    if (menu->slider != NULL)
        destroy_slider(menu->slider);
    if (menu->windowed != NULL)
        destroy_button(menu->windowed);
    free(menu);
}

void destroy_pause_menu(pause_menu_t *menu)
{
    if (menu == NULL)
        return;
    if (menu->act_volume != NULL)
        sfText_destroy(menu->act_volume);
    if (menu->back_menu != NULL)
        destroy_button(menu->back_menu);
    if (menu->background != NULL)
        destroy_image(menu->background);
    if (menu->camera != NULL)
        sfView_destroy(menu->camera);
    if (menu->first_resolution != NULL)
        destroy_button(menu->first_resolution);
    if (menu->fullscreen != NULL)
        destroy_button(menu->fullscreen);
    if (menu->resume != NULL)
        destroy_button(menu->resume);
    if (menu->save != NULL)
        destroy_button(menu->save);
    destroy_pause_menu2(menu);
}
