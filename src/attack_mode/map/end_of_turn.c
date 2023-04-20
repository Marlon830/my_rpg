/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** end_of_turn.c
*/

#include "attack_mode.h"



void end_of_turn(combat_player_t *player, hand_t *hand, battle_scene_t *scene)
{
    if (player->state != MOVING)
        return;
    set_player_stats(player);
    for (int i = 0; i < 3; i++)
        if (hand->nb_cards < 12)
            add_card_to_hand(hand, "card", (rand() + 1) % 100,
            (rand() + 1) % 10 + 1);
    for (int i = 0; i < scene->nb_enemies; i++) {
        enemy_attack(scene->enemies[i], scene);
        for (int j = i; j < scene->nb_enemies; j++)
            scene->enemies[j]->tiles_close = get_enemy_tiles_close(scene,
            scene->enemies[j]->actual_tile, scene->enemies[j]->
            actual_stats->move_points, scene->enemies[j]);
        set_enemy_pos(scene->enemies[i]);
        scene->enemies[i]->actual_stats->move_points =
        scene->enemies[i]->basic_stats->move_points;
    }
}
