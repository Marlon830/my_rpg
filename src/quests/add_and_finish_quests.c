/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** manage_quests.c
*/

#include "project.h"

void add_quest(char *quest_to_add, quest_t *quests, char *quest_id)
{
    push_back(&quests->actual_quests_list, quest_id,
    (char *) quest_to_add, QUEST);
    update_quest(quests);
}

void finish_quest(char *quest_id, quest_t *quests)
{
    list_t *temp_act_quests_list = quests->actual_quests_list;

    if (temp_act_quests_list == NULL)
        return;
    while (temp_act_quests_list != NULL) {
        if (my_strcmp(quest_id, temp_act_quests_list->id) == 0)
            break;
        temp_act_quests_list = temp_act_quests_list->next;
    }
    delete_item(&quests->actual_quests_list, quest_id);
    push_back(&quests->finished_quests_list, quest_id,
    (char *) temp_act_quests_list->element, QUEST);
    update_quest(quests);
}
