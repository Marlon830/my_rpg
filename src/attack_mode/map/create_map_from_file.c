/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** create_map_from_file.c
*/

#include "attack_mode.h"

tile_t *get_tile_from_str(char *line, sfVector2f size, sfVector2f decalage)
{
    int len = 0;
    int tileSize = size.x + 5;
    int x = my_getnbr(line);
    len += int_len(x) + 1;
    int y = my_getnbr(line + len);
    len += int_len(y) + 1;
    float height = my_getnbr(line + len);
    sfVector2f pos = (sfVector2f){(x * tileSize + y * tileSize)
            / 2 + decalage.x, (x * tileSize - y * tileSize) /
            (2 * (size.x / size.y)) + decalage.y};
    return create_tile(pos, sfWhite, size, height);
}

int count_char_until(char *str, char until)
{
    int i = 0;
    while (str[i] && str[i] != until)
        i++;
    return i;
}

char *get_line(char *str, int ind)
{
    int i = 0;
    int c = 0;
    int d = 0;
    while (str[i] && c != ind) {
        c += (str[i] == '\n');
        i++;
    }
    if (str[i] == 0)
        return NULL;
    char *res = malloc(sizeof(char) * (count_char_until(str + i, '\n') + 1));
    for (; str[i] && str[i] != '\n'; i++)
        res[d++] = str[i];
    return res;
}

int get_width_height(map_t *map, char *text_information)
{
    int len = 0;
    int width = my_getnbr(text_information);
    len += int_len(width) + 1;
    int height = my_getnbr(text_information + len);
    len += int_len(height) + 1;

    map->width = width;
    map->height = height;
    return len;
}

map_t *create_map_from_file(char *filename, sfVector2f size, sfVector2f pos)
{
    map_t *map = load_map(filename, size, pos);
    save_map(map);
    map = load_map(filename, size, pos);
    save_map(map);
    return map;
}
