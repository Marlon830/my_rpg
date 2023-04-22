/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_tutorial.c
*/

#include "attack_mode.h"

sfText *create_text_tuto(char *text, sfVector2f pos)
{
    sfText *res = sfText_create();
    sfText_setColor(res, sfWhite);
    sfText_setOutlineThickness(res, 2);
    sfText_setOutlineColor(res, sfBlack);
    sfFont *font = sfFont_createFromFile("assets/font/AldotheApache.ttf");
    sfText_setFont(res, font);
    sfText_setPosition(res, pos);
    sfText_setString(res, text);
    return res;
}

tutorial_t *create_tutorial(void)
{
    tutorial_t *res = malloc(sizeof(tutorial_t));
    res->arrow = create_arrow((sfVector2f){0, 0}, 50);
    res->left_click = create_sprite("assets/fight_tutorial/left_click.png",
    (sfVector2f){20, 100});
    sfSprite_setScale(res->left_click->sprite, (sfVector2f){.2, .2});
    res->right_click = create_sprite("assets/fight_tutorial/right_click.png",
    (sfVector2f){20, 200});
    sfSprite_setScale(res->right_click->sprite, (sfVector2f){.2, .2});
    res->space_bar = create_sprite("assets/fight_tutorial/space_bar.png",
    (sfVector2f){20, 300});
    sfSprite_setScale(res->space_bar->sprite, (sfVector2f){.2, .2});
    res->left_click_text =
    create_text_tuto("pour se deplacer et selectionner une carte d'attaque",
    (sfVector2f){70, 120});
    res->right_click_text = create_text_tuto("pour annuler l'attaque actuelle",
    (sfVector2f){70, 220});
    res->space_bar_text = create_text_tuto("pour terminer le tour",
    (sfVector2f){20, 350});
    return res;
}
