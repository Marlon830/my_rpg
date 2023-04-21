/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** create_battle_scene.c
*/

#include "attack_mode.h"

battle_scene_t *create_battle_scene(int width, int height,
sfVector2f tile_size)
{
    sfVector2f pos = (sfVector2f){960 - (width * tile_size.x) / 2, 500};
    battle_scene_t *res = malloc(sizeof(battle_scene_t));
    combat_map_t *map = create_map(width, height, pos , tile_size);
    res->enemies = create_enemies_from_txt
    ("assets/fight_scene/theoronfle_enemies.txt", map, &res->nb_enemies);
    combat_player_t *player = create_player(map->tiles[0]);
    hand_t *hand = create_hand(1, res->player);
    player->tiles_close = get_tiles_close(res, player->actual_tile,
    player->actual_stats->move_points, player);
    res->map = map;
    res->player = player;
    res->hand = hand;
    res->hand->player = player;
    res->win = 0;
    res->view = sfView_create();
    res->lazer = create_lazer(res->player->actual_tile->pos,
    res->enemies[0]->actual_tile->pos, 5);
    sfView_setSize(res->view, (sfVector2f){1920, 1080});
    sfView_setCenter(res->view, (sfVector2f){960, 540});
    return res;
}
