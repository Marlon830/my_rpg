/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** update_player.c
*/

#include "attack_mode.h"

void update_player_overlay(combat_player_t *player)
{
    char *hp = my_strcat("hp ", int_to_str(player->actual_stats->health_point));
    char *energy = my_strcat("energy ",
    int_to_str(player->actual_stats->energy_points));
    char *move_points = my_strcat("move ",
    int_to_str(player->actual_stats->move_points));
    update_combat_text(hp, player->overlay[0]->text);
    update_combat_text(energy, player->overlay[1]->text);
    update_combat_text(move_points, player->overlay[2]->text);
    free(hp);
    free(move_points);
    free(energy);


}

void update_player(combat_player_t *player)
{
    sfVertexArray_clear(player->array_character);
    set_player_pos(player);
    if (player->actual_stats->energy_points < 0)
        player->actual_stats->energy_points = 0;
    update_player_overlay(player);
}
