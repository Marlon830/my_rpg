/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** save_quest.c
*/

#include "project.h"

char *get_quest_name(char *buffer)
{
    char *ans = malloc(sizeof(char) * my_strlen(buffer));
    int i = 0;

    for (; buffer[i] != '|'; i++)
        ans[i] = buffer[i];
    ans[i] = '\0';
    return ans;
}

char *get_quest_id(char *buffer)
{
    char *ans = malloc(sizeof(char) * my_strlen(buffer));
    int i = 0;
    int j = 0;

    for (; buffer[i] != '|'; i++);
    i++;
    for (; buffer[i] != '\n'; i++)
        ans[j++] = buffer[i];
    ans[j] = '\0';
    return ans;
}

void get_quests(project_t *project, FILE *fp)
{
    char *buffer = NULL;
    size_t len = 0;
    int j = 0;

    while (1) {
        j = getline(&buffer, &len, fp);
        if (buffer[0] == '-')
            break;
        add_quest(get_quest_name(buffer), project->quests,
        get_quest_id(buffer));

    }
    while (1) {
        j = getline(&buffer, &len, fp);
        if (j == -1)
            break;
        finish_quest(get_quest_id(buffer), project->quests);

    }
}

void write_all_quest(list_t *temp_act_quest, list_t *temp_fi_quest, char *ans,
    int fd)
{
    while (temp_act_quest != NULL) {
        ans = my_strcat(temp_act_quest->element, "|");
        ans = my_strcat(ans, temp_act_quest->id);
        write(fd, my_strcat(ans, "\n"),
        my_strlen(ans) + 1);
        temp_act_quest = temp_act_quest->next;
    }
    while (temp_fi_quest != NULL) {
        ans = my_strcat(temp_fi_quest->element, "|");
        ans = my_strcat(ans, temp_fi_quest->id);
        write(fd, my_strcat(ans, "\n"),
        my_strlen(ans) + 1);
        temp_fi_quest = temp_fi_quest->next;
    }
}

void save_quests(project_t *project, int fd)
{
    list_t *temp_act_quest = project->quests->actual_quests_list;
    list_t *temp_fi_quest = project->quests->finished_quests_list;
    char *ans = NULL;

    write_all_quest(temp_act_quest, temp_fi_quest, ans, fd);
    write(fd, "-\n", 2);
    temp_fi_quest = project->quests->finished_quests_list;
    while (temp_fi_quest != NULL) {
        ans = my_strcat(temp_fi_quest->element, "|");
        ans = my_strcat(ans, temp_fi_quest->id);
        write(fd, my_strcat(ans, "\n"),
        my_strlen(ans) + 1);
        temp_fi_quest = temp_fi_quest->next;
    }
}
