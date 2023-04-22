/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_quest.c
*/

#include "project.h"

void destroy_quest(quest_t *quest)
{
    if (quest == NULL)
        return;
    if (quest->actual_quests_rect != NULL)
        sfRectangleShape_destroy(quest->actual_quests_rect);
    if (quest->actual_quests_text != NULL)
        sfText_destroy(quest->actual_quests_text);
    if (quest->finished_quests_rect != NULL)
        sfRectangleShape_destroy(quest->finished_quests_rect);
    if (quest->finished_quests_text != NULL)
        sfText_destroy(quest->finished_quests_text);
    free(quest);
}
