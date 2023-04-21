/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_lazer.c
*/

#include "attack_mode.h"

sfVector2f racine_nieme(int k, int n)
{
    sfVector2f res;
    res.x = cos((2 * k * pi) / n);
    res.y = sin((2 * k * pi) / n);
    return res;
}

void append_vertex(sfVector2f point, sfColor color, sfVertexArray *array)
{
    sfVertexArray_append(array, (sfVertex){point, color, point});
}

void circle_shape(sfVector2f p1, sfVector2f p2, float radius,
sfVertexArray *array)
{
    sfVector2f racine;
    float thickness = radius;
    sfColor color = sfRed;
    for (int i = 0; i < 15; i++) {
        racine = racine_nieme(i, 15);
        sfVector2f p3 = (sfVector2f){(racine.x * thickness) + p1.x,
        (racine.y * thickness) + p1.y};
        sfVector2f p4 = (sfVector2f){(racine.x * thickness) + p2.x,
        (racine.y * thickness) + p2.y};
        racine = racine_nieme(i - 1, 15);
        sfVector2f p5 = (sfVector2f){(racine.x * thickness) + p1.x,
        (racine.y * thickness) + p1.y};
        append_vertex(p1, color, array);
        append_vertex(p3, color, array);
        append_vertex(p5, color, array);
        append_vertex(p2, color, array);
        append_vertex(p4, color, array);
    }
    sfVertexArray_setPrimitiveType(array, sfTriangleStrip);
}

lazer_t *create_lazer(sfVector2f start, sfVector2f end, float radius)
{
    lazer_t *res = malloc(sizeof(lazer_t));
    res->array = sfVertexArray_create();
    res->clock = sfClock_create();
    res->end = end;
    res->start = start;
    res->radius = radius;
    res->show = 0;
    circle_shape(res->start, res->end, radius, res->array);
    return res;
}
