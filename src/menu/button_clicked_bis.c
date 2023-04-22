/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_clicked_bis.c
*/

#include "project.h"

void back_menu_button(project_t *project)
{
    sfMusic_stop(project->main_menu->music_ingame);
    project->status = MAIN_MENU;
    project->main_menu->save = get_save(project);
    sfMusic_play(project->main_menu->music);
}

void resume_button(project_t *project)
{
    project->status = GAME;
}

void new_game_button_bis(project_t *project)
{
    sfMusic_play(project->main_menu->music_ingame);
    project->quests->actual_quests_list = NULL;
    project->quests->finished_quests_list = NULL;
    update_quest(project->quests);
    destroy_stats(project->player->player_stats);
    project->player->player_stats = init_stats();
}

void new_game_button(project_t *project)
{
    int fd = open("save", O_WRONLY | O_CREAT, 0644);
    project->status = GAME;
    project->player->pos.x = 384;
    project->player->pos.y = 416;
    project->inventory = create_inventory();
    project->player->player_progress_state = 0;
    project->main_menu->save = NULL;
    destroy_inventory(project->inventory);
    project->inventory = create_inventory();
    destroy_equipment(project->player->equipment);
    project->player->equipment = init_equipment();
    write(fd, "R", 1);
    project->scene = load_scene(project, 0);
    sfMusic_stop(project->main_menu->music);
    project->main_menu->state = NAUNE;
    new_game_button_bis(project);
    close(fd);
}
