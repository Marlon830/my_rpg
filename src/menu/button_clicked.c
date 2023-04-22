/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_clicked.c
*/

#include "project.h"

void load_game_button(project_t *project)
{
    save_t *save = project->main_menu->save;

    project->status = GAME;
    project->player->player_progress_state = save->player_state;
    project->player->player_second_state = save->player_second_state;
    project->player->pos.x = save->pos.x;
    project->player->pos.y = save->pos.y;
    project->player->col->left = project->player->pos.x;
    project->player->col->top = project->player->pos.y + 8;
    project->scene = load_scene(project, save->scene_id);
    project->main_menu->state = NAUNE;
    sfMusic_stop(project->main_menu->music);
    sfMusic_play(project->main_menu->music_ingame);
}

void display_play(project_t *project)
{
    project->main_menu->state = PLAY;
}

void display_settings(project_t *project)
{
    project->main_menu->state = SETTINGS;
}

void quit_button(project_t *project)
{
    sfRenderWindow_close(project->window);
}
