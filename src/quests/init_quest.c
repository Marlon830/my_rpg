/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_quest.c
*/

#include "project.h"

quest_t *init_quests(void)
{
    quest_t *quests = malloc(sizeof(quest_t));

    quests->actual_quests_list = NULL;
    quests->actual_quests_rect = sfRectangleShape_create();
    quests->actual_quests_text = create_text((sfVector2f) {0, 0},
    (sfVector2f) {0.1, 0.1}, sfWhite);
    quests->finished_quests_list = NULL;
    quests->finished_quests_rect = sfRectangleShape_create();
    quests->finished_quests_text = create_text((sfVector2f) {0, 0},
    (sfVector2f) {0.1, 0.1}, sfWhite);
    quests->is_act_disp = -1;
    return quests;
}
