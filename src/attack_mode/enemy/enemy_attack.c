/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** enemy_attack.c
*/

#include "attack_mode.h"

void hit_player(battle_scene_t *scene, tile_t *tile, int damage)
{
    char *text = int_to_str(MAX(damage -
    scene->player->actual_stats->defense, 0));
    scene->player->actual_stats->health_point += MIN(-damage +
    scene->player->actual_stats->defense, 0);
    sfText_setString(scene->player->damage_taken->text, text);
    scene->player->damage_taken->show = 1;
    sfText_setPosition(scene->player->damage_taken->text,
    (sfVector2f){tile->pos.x - my_strlen(text) * 7, tile->pos.y - 80});
    free(text);
}

void enemy_attack(enemy_t *enemy, battle_scene_t *scene)
{
    if (enemy == NULL)
        return;
    enemy_get_close_to_player(enemy, scene);
    if (manhattan_dist(get_pos_in_tiles(scene->map, enemy->actual_tile),
    get_pos_in_tiles(scene->map, scene->player->actual_tile)) <=
    enemy->range) {
        hit_player(scene, scene->player->actual_tile,
        enemy->actual_stats->damage);
        destroy_lazer(scene->lazer);
        scene->lazer = create_lazer(enemy->actual_tile->pos,
        scene->player->actual_tile->pos, enemy->actual_stats->damage / 10.);
        scene->lazer->show = 1;
    }
}
