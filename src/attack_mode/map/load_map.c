/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** load_map.c
*/

#include "attack_mode.h"

tile_t **put_tiles(char *text_information, sfVector2f size,
sfVector2f pos, combat_map_t *res)
{
    int height = count_char_in_str(text_information, '\n');
    char *line;
    tile_t **tiles = malloc(sizeof(tile_t *) * height);
    text_information += get_width_height(res, text_information);
    for (int i = 0; i < height; i++) {
        line = get_line(text_information, i);
        tiles[i] = get_tile_from_str(line, size, pos);
        free(line);
    }
    return tiles;
}

combat_map_t *load_map(char *filename, sfVector2f size, sfVector2f pos)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        write(2, "file does not exists.\n", 22);
        return NULL;
    }
    combat_map_t *res = malloc(sizeof(combat_map_t));
    struct stat st;
    int ind = 0;
    stat(filename, &st);
    char *text_information = malloc(sizeof(char) * st.st_size);
    read(fd,text_information ,st.st_size);
    text_information[st.st_size] = 0;
    res->tiles = put_tiles(text_information, size, pos, res);
    close(fd);
    res->pos = pos;
    res->hovered_tile = res->tiles[0];
    return res;
}
