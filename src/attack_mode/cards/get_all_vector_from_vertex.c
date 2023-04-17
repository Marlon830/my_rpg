/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_all_vector_from_vertex.c
*/

#include "attack_mode.h"

sfVector2f *get_all_vector_from_vertex(sfVertexArray *array)
{
    int len = sfVertexArray_getVertexCount(array);
    sfVector2f *res = malloc(sizeof(sfVector2f) * len);

    for (int i = 0; i < len; i++) {
        res[i] = sfVertexArray_getVertex(array, i)->position;
    }
    return res;
}
