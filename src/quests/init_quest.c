/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_quest.c
*/

#include "project.h"

quest_t *init_quests_bis(quest_t *quests, sfTexture *texture)
{
    quests->finished_quests_list = NULL;
    quests->finished_quests_rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(quests->finished_quests_rect,
    (sfColor) {255, 255, 255, 180});
    sfRectangleShape_setSize(quests->finished_quests_rect, (sfVector2f)
    {32 * 1.65, 48 * 1.65});
    sfRectangleShape_setTexture(quests->finished_quests_rect, texture, sfTrue);
    quests->finished_quests_text = create_text((sfVector2f) {0, 0},
    (sfVector2f) {0.1, 0.1}, sfGreen);
    quests->is_act_disp = -1;
    return quests;
}

quest_t *init_quests(void)
{
    quest_t *quests = malloc(sizeof(quest_t));
    sfTexture *texture = sfTexture_createFromFile("assets/quest.png", NULL);

    quests->actual_quests_list = NULL;
    quests->actual_quests_rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(quests->actual_quests_rect,
    (sfColor) {255, 255, 255, 180});
    sfRectangleShape_setSize(quests->actual_quests_rect, (sfVector2f)
    {32 * 1.65, 48 * 1.65});
    sfRectangleShape_setTexture(quests->actual_quests_rect, texture, sfTrue);
    quests->actual_quests_text = create_text((sfVector2f) {0, 0},
    (sfVector2f) {0.1, 0.1}, sfWhite);
    return init_quests_bis(quests, texture);
}
