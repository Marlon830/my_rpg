/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_project.c
*/

#include "project.h"
#include "utils.h"

player_t *init_player(int x, int y)
{
    player_t *player = malloc(sizeof(player_t));
    player->col = malloc(sizeof(sfFloatRect));
    player->pos.x = x;
    player->pos.y = y;
    player->col->left = player->pos.x;
    player->col->top = player->pos.y;
    player->col->width = 10;
    player->col->height = 8;
    player->speed = 1;
    player->move = (sfVector2f) {0, 0};
    player->state = IDLE_DOWN;
    player->player_progress_state = 0;
    player->equipment = malloc(sizeof(player->equipment) * 13);
    player->equipment->helmet = NULL;
    player->equipment->armor = NULL;
    player->equipment->pants = NULL;
    player->equipment->boots = NULL;
    player->equipment->sword = NULL;
    player->equipment->shield = NULL;
    return player;
}

act_dial_t *init_actual_dialogue(void)
{
    act_dial_t *actual_dial = malloc(sizeof(act_dial_t));

    actual_dial->pos = 0;
    actual_dial->text = create_text((sfVector2f){160, 160},
    (sfVector2f){0.2, 0.2}, sfWhite);
    actual_dial->rect = create_rect();
    actual_dial->is_displayed = 0;
    return actual_dial;
}

project_t *init_project_bis(project_t *project)
{
    project->main_menu = init_main_menu(project);
    project->pause_menu = init_pause_menu(project);
    project->actual_dial = init_actual_dialogue();
    project->all_dialogues = create_all_dialogues(project, "assets/dialogues");
    project->battle_scene = create_standard_battle_scene();
    project->quests = init_quests();
    project->fight_win = 0;
    project->volume = 100;
    project->is_fullscreen = 1;
    return project;
}

project_t *init_project(void)
{
    project_t *project = malloc(sizeof(project_t));
    project->mode = (sfVideoMode){1920, 1080, 32};
    project->inventory = create_inventory();
    project->window = sfRenderWindow_create(mode, "Quoi ? Feur",
    sfClose | sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(project->window, 60);
    sfRenderWindow_setKeyRepeatEnabled(project->window, sfFalse);
    project->clock = sfClock_create();
    project->player = init_player(384, 416);
    project->scenes = NULL;
    project->scene = NULL;
    project->status = MAIN_MENU;
    return init_project_bis(project);
}
