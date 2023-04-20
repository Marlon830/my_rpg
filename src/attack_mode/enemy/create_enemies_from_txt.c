/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_enemies_from_txt.c
*/

#include "attack_mode.h"

enemy_t *create_enemies_from_pos(int x, int y, combat_map_t *map,
char *filename)
{
    return create_enemy(map->tiles[x * map->height + y], filename);
}

void change_stat(enemy_t *enemy, int damage, int health_point, int move_point)
{
    enemy->actual_stats->damage = damage;
    enemy->actual_stats->health_point = health_point;
    enemy->actual_stats->move_points = move_point;
    enemy->basic_stats->damage = damage;
    enemy->basic_stats->health_point = health_point;
    enemy->basic_stats->move_points = move_point;
}

int set_enemy(char *buffer, combat_map_t *map, enemy_t **res, int i)
{
    int x = my_getnbr(buffer);
    buffer += int_len(x) + 1;
    int y = my_getnbr(buffer);
    buffer += int_len(y) + 1;
    int damage = my_getnbr(buffer);
    buffer += int_len(damage) + 1;
    int range = my_getnbr(buffer);
    buffer += int_len(range) + 1;
    int health = my_getnbr(buffer);
    buffer += int_len(health) + 1;
    int move_point = my_getnbr(buffer);
    char *filename = get_str_until(buffer + int_len(move_point) + 1, '\n');
    int k = my_strlen(filename);
    res[i] = create_enemies_from_pos(x, y, map, filename);
    free(filename);
    change_stat(res[i], damage, health, move_point);
    res[i]->range = range;
    return int_len(x) + int_len(y) + int_len(damage) + int_len(range) +
    int_len(health) + int_len(move_point) + k + 7;
}

enemy_t **create_enemies_from_txt(char *filename, combat_map_t *map,
int *nb_enemies)
{
    int fd = open(filename, O_RDONLY);
    struct stat st;
    stat(filename, &st);
    char *buffer = malloc(sizeof(char) * (st.st_size + 1));
    buffer[st.st_size] = 0;
    read(fd, buffer, st.st_size);
    *nb_enemies = my_getnbr(buffer);
    buffer += int_len(*nb_enemies) + 1;
    enemy_t **res = malloc(sizeof(enemy_t *) * *nb_enemies);
    for (int i = 0; i < *nb_enemies; i++) {
        buffer += set_enemy(buffer, map, res, i);
    }
    close(fd);
    return res;
}
