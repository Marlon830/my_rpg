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

int get_width_height(combat_map_t *map, FILE *stream)
{
    char *line = NULL;
    size_t len;
    getline(&line, &len, stream);
    int width = my_getnbr(line);
    int height = my_getnbr(line + int_len(width) + 1);

    map->width = width;
    map->height = height;
    return my_strlen(line);
}

combat_map_t *create_map_from_file(char *filename, sfVector2f size)
{
    combat_map_t *map = load_map(filename, size);
    map->hovered_tile = map->tiles[0];
    map->far_tile = create_tile((sfVector2f)
    {-100, -100}, sfWhite, (sfVector2f){1, 1}, 0);
    map->far_tile->ind = -1;
    return map;
}
