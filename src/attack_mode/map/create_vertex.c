/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_vertex.c
*/

#include "attack_mode.h"

sfvertex vertex_create(sfVector2f position, sfColor color)
{
    sfVertex res = (sfVertex){position, color, position};
    return res;
}
