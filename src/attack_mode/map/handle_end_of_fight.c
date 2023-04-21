/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handle_end_of_fight.c
*/

#include "attack_mode.h"
#include "project.h"

void reset_equipment2(equipment_t *equip)
{
    if (equip->amulet != NULL) {
        sfSprite_setScale(equip->amulet, (sfVector2f) {1, 1});
        sfSprite_setOrigin(equip->amulet, (sfVector2f) {0, 0});
    }
    if (equip->ring != NULL) {
        sfSprite_setScale(equip->ring, (sfVector2f) {1, 1});
        sfSprite_setOrigin(equip->ring, (sfVector2f) {0, 0});
    }
    if (equip->sword != NULL) {
        sfSprite_setScale(equip->sword, (sfVector2f) {1, 1});
        sfSprite_setOrigin(equip->sword, (sfVector2f) {0, 0});
    }
    if (equip->shield != NULL) {
        sfSprite_setScale(equip->shield, (sfVector2f) {1, 1});
        sfSprite_setOrigin(equip->shield, (sfVector2f) {0, 0});
    }
}

void reset_equipment(equipment_t *equip)
{
    if (equip->helmet != NULL) {
        sfSprite_setScale(equip->helmet, (sfVector2f) {1, 1});
        sfSprite_setOrigin(equip->helmet, (sfVector2f) {0, 0});
    }
    if (equip->armor != NULL) {
        sfSprite_setScale(equip->armor, (sfVector2f) {1, 1});
        sfSprite_setOrigin(equip->armor, (sfVector2f) {0, 0});
    }
    if (equip->pants != NULL) {
        sfSprite_setScale(equip->pants, (sfVector2f) {1, 1});
        sfSprite_setOrigin(equip->pants, (sfVector2f) {0, 0});
    }
    if (equip->boots != NULL) {
        sfSprite_setScale(equip->boots, (sfVector2f) {1, 1});
        sfSprite_setOrigin(equip->boots, (sfVector2f) {0, 0});
    }
    reset_equipment2(equip);
}

void handle_end_of_fight(project_t *project)
{
    project->fight_win = project->battle_scene->win;
    if (project->battle_scene->win == -1 || project->battle_scene->win == 1) {
        upscale_player_stats(project->player->player_stats,
        (sfVector2f){.08, .08});
        update_player_stats(project->player->player_stats,
        project->battle_scene->player->basic_stats);
        destroy_battle_scene(project->battle_scene);
        project->battle_scene = NULL;
        project->status = GAME;
        reset_equipment(project->player->equipment);
        project->scene = load_scene(project, project->scene_id);
        set_state_with_end_of_fight(project);
    }
}
