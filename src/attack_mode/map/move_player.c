/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** move_player.c
*/

#include "attack_mode.h"

void hit_enemy(battle_scene_t *scene, tile_t *tile, int damage)
{
    char *text = int_to_str(damage);
    for (int i = 0; i < scene->nb_enemies; i++) {
        if (scene->enemies[i] != NULL && tile->ind ==
        scene->enemies[i]->actual_tile->ind) {
            scene->enemies[i]->actual_stats->health_point -= damage;
            scene->enemies[i]->damage_taken->show = 1;
            sfText_setString(scene->enemies[i]->damage_taken->text, text);
            sfText_setPosition(scene->enemies[i]->damage_taken->text,
            (sfVector2f){tile->pos.x - my_strlen(text) * 7, tile->pos.y - 80});
            free(text);
            return;
        }
    }
    free(text);
}

void attack_player(combat_player_t *player, tile_t *tile, combat_map_t *map,
battle_scene_t *scene)
{
    if (!(player->state == ATTACKING && player->card))
        return;
    for (int i = 0; i < player->nb_attack_tiles; i++) {
        if (player->attack_tiles[i]->ind == tile->ind) {
            hit_enemy(scene, tile, player->actual_stats->damage +
            player->card->damage);
            free(player->card);
            player->state = MOVING;
            player->card = NULL;
            return;
        }
    }
}

void move_player(combat_player_t *player, tile_t *tile, combat_map_t *map,
battle_scene_t *scene)
{
    if (player->state != MOVING) {
        attack_player(player, tile, map, scene);
        return;
    }
    if (tile->ind == -1)
        return;
    sfVector2f pos = (sfVector2f){(tile->ind - (tile->ind % map->height))
    / map->height, tile->ind % map->height};
    sfVector2f pos2 = (sfVector2f){(player->actual_tile->ind -
    (player->actual_tile->ind % map->height))
    / map->height, player->actual_tile->ind % map->height};
    for (int i = 0; i < player->nb_tiles_close; i++) {
        if (player->tiles_close[i]->ind == tile->ind) {
            player->actual_stats->move_points -= manhattan_dist(pos2, pos);
            player->actual_tile = tile;
            return;
        }
    }
}