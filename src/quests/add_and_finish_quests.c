/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** manage_quests.c
*/

#include "project.h"

void add_quest(char *quest_to_add, quest_t *quests, char *quest_id)
{
    list_t *temp = quests->actual_quests_list;
    list_t *temp2 = quests->finished_quests_list;

    while (temp2 != NULL) {
        if (!my_strcmp(temp2->id, quest_id))
            return;
        temp2 = temp2->next;
    }
    while (temp != NULL) {
        if (my_strcmp(temp->id, quest_id) == 0)
            return;
        temp = temp->next;
    }
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
    if (temp_act_quests_list == NULL)
        return;
    delete_item(&quests->actual_quests_list, quest_id);
    push_back(&quests->finished_quests_list, quest_id,
    (char *) temp_act_quests_list->element, QUEST);
    update_quest(quests);
}
