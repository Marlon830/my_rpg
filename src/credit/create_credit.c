/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_credit.c
*/

#include "project.h"

credit_t *create_credit(void)
{
    credit_t *credit = malloc(sizeof(*credit));
    credit->string = get_file("assets/credit/credit.txt");

    credit->clock_credit = sfClock_create();
    credit->text = sfText_create();
    sfText_setString(credit->text, credit->string);
    sfText_setScale(credit->text, (sfVector2f) {1, 1});
    credit->font = sfFont_createFromFile("assets/font/Roboto-Regular.ttf");
    sfText_setFont(credit->text, credit->font);
    sfText_setColor(credit->text, sfWhite);
    credit->pos.x = 800;
    credit->pos.y = 1660;
    credit->music = sfMusic_createFromFile("assets/music/epic_music.ogg");
    return credit;
}
