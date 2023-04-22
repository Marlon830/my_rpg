/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_quest.c
*/

#include "project.h"

int get_nb_of_quest(list_t *quests)
{
    list_t *temp_quest = quests;
    int i = 0;

    while (temp_quest != NULL) {
        i++;
        temp_quest = temp_quest->next;
    }
    return i;
}

int get_max_quest_len(list_t *quests)
{
    list_t *temp_quest = quests;
    int i = 0;
    int len = 0;

    while (temp_quest != NULL) {
        len = my_strlen((char *) temp_quest->element);
        if (i < len)
            i = len;
        temp_quest = temp_quest->next;
    }
    return i;
}

char *my_quest_cat(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    for (; s1[j] != '\0'; j++);
    for (; s2[i] != '\0'; i++)
        s1[j++] = s2[i];
    s1[j] = '\n';
    s1[j + 1] = '\0';
    return s1;
}

void update_quest_list(list_t *quests_list, sfText *quest_text)
{
    list_t *temp_act_quest = quests_list;
    int nb_of_quest = get_nb_of_quest(quests_list);
    char *ans = malloc(sizeof(char) *
    (get_max_quest_len(quests_list) * (nb_of_quest * 3)));

    ans[0] = '\0';
    while (temp_act_quest != NULL) {
        ans = my_quest_cat(ans, (char *) temp_act_quest->element);
        temp_act_quest = temp_act_quest->next;
    }
    sfText_setString(quest_text, ans);
}

void update_quest(quest_t *quests)
{
    if (quests->actual_quests_list != NULL)
        update_quest_list(quests->actual_quests_list,
        quests->actual_quests_text);
    else
        sfText_setString(quests->actual_quests_text, "\0");
    if (quests->finished_quests_list != NULL)
        update_quest_list(quests->finished_quests_list,
        quests->finished_quests_text);
    else
        sfText_setString(quests->finished_quests_text, "\0");
}
