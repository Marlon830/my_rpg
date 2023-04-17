/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_standard_battle_scene.c
*/

#include "attack_mode.h"

battle_scene_t *create_standard_battle_scene(void)
{
    return create_battle_scene(30, 30,
    (sfVector2f){100, 500}, (sfVector2f){50, 25});
}
