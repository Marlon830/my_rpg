/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_arrow.c
*/

#include "attack_mode.h"

void setup_arrow_array(sfVertexArray *array, sfVector2f pos, float size)
{
    sfVertexArray_clear(array);
    sfVector2f p1 = pos;
    sfVector2f p2 = {p1.x - size, p1.y - 1.5 * size};
    sfVector2f p3 = {p1.x - size, p1.y - .5 * size};
    sfVector2f p4 = {p1.x - 4 * size, p1.y - .5 * size};
    sfVector2f p5 = {p1.x - 4 * size, p1.y + .5 * size};
    sfVector2f p6 = {p1.x - size, p1.y + .5 * size};
    sfVector2f p7 = {p1.x - size, p1.y + 1.5 * size};
    append_vertex(p1, sfRed, array);
    append_vertex(p2, sfRed, array);
    append_vertex(p3, sfRed, array);
    append_vertex(p4, sfRed, array);
    append_vertex(p5, sfRed, array);
    append_vertex(p6, sfRed, array);
    append_vertex(p7, sfRed, array);
    sfVertexArray_setPrimitiveType(array, sfTrianglesFan);
}

arrow_t *create_arrow(sfVector2f pos, float size)
{
    arrow_t *res = malloc(sizeof(arrow_t));
    res->pos = pos;
    res->angle = 0;
    res->size = size;
    res->text = sfText_create();
    res->array = sfVertexArray_create();
    setup_arrow_array(res->array, res->pos, res->size);
    return res;
}
