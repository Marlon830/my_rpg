/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_manager4.c
*/

#include "project.h"

char *get_stat_path(char *path)
{
    int len = my_strlen(path);
    char *new_path = malloc(len + 1);

    my_strcpy(new_path, "assets/");
    my_strcpy(new_path + my_strlen(new_path), "stats/");
    my_strcpy(new_path + my_strlen(new_path), path + 14);
    new_path[len - 1] = '\0';
    new_path[len - 2] = 't';
    new_path[len - 3] = 'x';
    new_path[len - 4] = 't';
    return new_path;
}

void analize_line2(player_t *player, char *line, int stat)
{
    if (line[0] == 'a')
        player->player_stats->attack_value -= stat;
    if (line[0] == 'd')
        player->player_stats->defense_value -= stat;
    if (line[0] == 'h')
        player->player_stats->health_value -= stat;
    if (line[0] == 'e')
        player->player_stats->mana_value -= stat;
    if (line[0] == 'm')
        player->player_stats->move_range_value -= stat;
}

void analize_line(player_t *player, char *line, int is_add)
{
    int stat = my_getnbr(line);

    if (is_add) {
        if (line[0] == 'a')
            player->player_stats->attack_value += stat;
        if (line[0] == 'd')
            player->player_stats->defense_value += stat;
        if (line[0] == 'h')
            player->player_stats->health_value += stat;
        if (line[0] == 'e')
            player->player_stats->mana_value += stat;
        if (line[0] == 'm')
            player->player_stats->move_range_value += stat;
        return;
    }
    analize_line2(player, line, stat);
}

void add_stat(player_t *player, char *path)
{
    char *new_path = get_stat_path(path);
    FILE *fp = fopen(new_path, "r");
    char *line = NULL;
    size_t len = 0;

    if (fp == NULL)
        return;
    getline(&line, &len, fp);
    analize_line(player, line, 1);
    getline(&line, &len, fp);
    analize_line(player, line, 1);
    getline(&line, &len, fp);
    analize_line(player, line, 1);
    getline(&line, &len, fp);
    analize_line(player, line, 1);
    getline(&line, &len, fp);
    analize_line(player, line, 1);
    fclose(fp);
}

void remove_stat(player_t *player, char *path)
{
    char *new_path = get_stat_path(path);
    FILE *fp = fopen(new_path, "r");
    char *line = NULL;
    size_t len = 0;

    if (fp == NULL)
        return;
    getline(&line, &len, fp);
    analize_line(player, line, 0);
    getline(&line, &len, fp);
    analize_line(player, line, 0);
    getline(&line, &len, fp);
    analize_line(player, line, 0);
    getline(&line, &len, fp);
    analize_line(player, line, 0);
    getline(&line, &len, fp);
    analize_line(player, line, 0);
    fclose(fp);
}
