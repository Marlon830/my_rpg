/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** load_map.c
*/

#include "attack_mode.h"

tile_t **put_tiles(char *text_information, sfVector2f size,
sfVector2f pos, FILE *stream)
{
    int height = count_char_in_str(text_information, '\n');
    char *line = NULL;
    size_t len = 0;
    tile_t **tiles = malloc(sizeof(tile_t *) * height);

    for (int i = 0; i < height; i++) {
        getline(&line, &len, stream);
        if (line != NULL) {
            tiles[i] = get_tile_from_str(line, size, pos);
            tiles[i]->ind = i;
        }
    }
    return tiles;
}

combat_map_t *load_map(char *filename, sfVector2f size)
{
    int fd = open(filename, O_RDONLY);
    FILE *stream = fopen(filename, "r");
    if (fd < 0) {
        write(2, "file does not exists.\n", 22);
        return NULL;
    }
    sfVector2f pos;
    combat_map_t *res = malloc(sizeof(combat_map_t));
    struct stat st;
    stat(filename, &st);
    char *text_information = malloc(sizeof(char) * (st.st_size + 1));
    read(fd,text_information ,st.st_size);
    text_information[st.st_size] = 0;
    text_information += get_width_height(res, stream);
    pos = (sfVector2f){960 - (res->width * size.x) / 2, 500};
    res->tiles = put_tiles(text_information, size, pos, stream);
    close(fd);
    res->pos = pos;
    res->hovered_tile = res->tiles[0];
    return res;
}
