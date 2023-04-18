/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_standard_battle_scene.c
*/

#include "attack_mode.h"

battle_scene_t *create_standard_battle_scene(void)
{
    return create_battle_scene_from_file(
    "assets/fight_scene/theoronfle_map.txt",
    "assets/fight_scene/theoronfle_enemies.txt");
    return create_battle_scene(10, 10, (sfVector2f){60, 35});
}
