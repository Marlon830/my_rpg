/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_credit.c
*/

#include "project.h"

void reset_view(project_t *project)
{
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f) {1920, 1080});
    sfView_setCenter(view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfRenderWindow_setView(WINDOW, view);
}

void update_credit(project_t *project, credit_t *credit)
{
    if (project->status != CREDIT)
        return;
    if (credit->pos.y <= -1100) {
        project->status = MAIN_MENU;
        credit->pos.y = 1080;
        return;
    }
    sfRenderWindow_clear(project->window, sfBlack);
    credit->time_credit = sfClock_getElapsedTime(credit->clock_credit);
    credit->seconds_credit = credit->time_credit.microseconds / 1000000.0;
    if (credit->seconds_credit > 0.01) {
        credit->pos.y -= 1;
        sfClock_restart(credit->clock_credit);
    }
    sfText_setString(credit->text, credit->string);
    sfText_setPosition(credit->text, credit->pos);
    sfRenderWindow_drawText(WINDOW, credit->text, NULL);
}
