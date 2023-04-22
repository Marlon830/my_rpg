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

void start_credit(project_t *project)
{
    project->status = CREDIT;
    reset_view(project);
    sfMusic_stop(project->main_menu->music_ingame);
    sfMusic_play(project->credit->music);
    sfMusic_setVolume(project->credit->music, project->volume);
    project->credit->volume = sfMusic_getVolume(project->credit->music);
}

void update_credit2(project_t *project, credit_t *credit)
{
    if (credit->seconds_credit > 0.01) {
        credit->pos.y -= 1;
        sfClock_restart(credit->clock_credit);
        if (credit->pos.y <= -1150 && (sfMusic_getVolume(credit->music) -
        credit->volume / 200) > 0)
            sfMusic_setVolume(credit->music, sfMusic_getVolume(credit->music) -
            credit->volume / 200);
    }
    sfText_setString(credit->text, credit->string);
    sfText_setPosition(credit->text, credit->pos);
    sfRenderWindow_drawText(WINDOW, credit->text, NULL);
}

void update_credit(project_t *project, credit_t *credit)
{
    if (project->status != CREDIT)
        return;
    if (credit->pos.y <= -1350) {
        project->status = MAIN_MENU;
        credit->pos.y = 1080;
        sfMusic_stop(credit->music);
        return;
    }
    sfRenderWindow_clear(project->window, sfBlack);
    credit->time_credit = sfClock_getElapsedTime(credit->clock_credit);
    credit->seconds_credit = credit->time_credit.microseconds / 1000000.0;
    update_credit2(project, credit);
}
