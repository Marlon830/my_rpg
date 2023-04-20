/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_stats.c
*/

#include "project.h"

player_stats_t *init_stats_bis(player_stats_t *player_stats)
{
    player_stats->health_image = create_image((sfVector2f) {0, 0},
    "stats/heart.png", (sfIntRect) {0, 0, 16, 16}, (sfVector2f) {0, 0});
    player_stats->attack_image = create_image((sfVector2f) {0, 0},
    "object/sword_silver.png", (sfIntRect) {0, 0, 16, 16}, (sfVector2f) {0, 0});
    player_stats->defense_image = create_image((sfVector2f) {0, 0},
    "object/armor_silver.png", (sfIntRect) {0, 0, 16, 16}, (sfVector2f) {0, 0});
    player_stats->move_range_image = create_image((sfVector2f) {0, 0},
    "object/boots_silver.png", (sfIntRect) {0, 0, 16, 16}, (sfVector2f) {0, 0});
    player_stats->mana_image = create_image((sfVector2f) {0, 0},
    "stats/mana.png", (sfIntRect) {0, 0, 16, 16}, (sfVector2f) {0, 0});
    player_stats->attack_name = create_text((sfVector2f)
    {0, 0}, (sfVector2f) {0.08, 0.08}, sfWhite);
    player_stats->defense_name = create_text((sfVector2f)
    {0, 0}, (sfVector2f) {0.08, 0.08}, sfWhite);
    player_stats->move_range_name = create_text((sfVector2f)
    {0, 0}, (sfVector2f) {0.08, 0.08}, sfWhite);
    player_stats->mana_name = create_text((sfVector2f)
    {0, 0}, (sfVector2f) {0.08, 0.08}, sfWhite);
    return player_stats;
}

player_stats_t *init_stats(void)
{
    player_stats_t *player_stats = malloc(sizeof(*player_stats));

    player_stats->attack_value = 10;
    player_stats->defense_value = 10;
    player_stats->health_value = 100;
    player_stats->mana_value = 10;
    player_stats->move_range_value = 3;
    player_stats->health_text_value = create_text((sfVector2f)
    {0, 0}, (sfVector2f) {0.1, 0.1}, sfWhite);
    player_stats->attack_text_value = create_text((sfVector2f)
    {0, 0}, (sfVector2f) {0.1, 0.1}, sfWhite);
    player_stats->defense_text_value = create_text((sfVector2f)
    {0, 0}, (sfVector2f) {0.1, 0.1}, sfWhite);
    player_stats->move_range_text_value = create_text((sfVector2f)
    {0, 0}, (sfVector2f) {0.1, 0.1}, sfWhite);
    player_stats->mana_text_value = create_text((sfVector2f)
    {0, 0}, (sfVector2f) {0.1, 0.1}, sfWhite);
    player_stats->health_name = create_text((sfVector2f)
    {0, 0}, (sfVector2f) {0.08, 0.08}, sfWhite);
    return init_stats_bis(player_stats);
}
