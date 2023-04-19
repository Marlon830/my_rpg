/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_stats.c
*/

#include "project.h"

void update_stats_four(project_t *project)
{
    sfSprite_setScale(project->player->player_stats->
    health_image->sprite, (sfVector2f) {0.2, 0.2});
    sfSprite_setScale(project->player->player_stats->
    attack_image->sprite, (sfVector2f) {0.2, 0.2});
    sfSprite_setScale(project->player->player_stats->
    defense_image->sprite, (sfVector2f) {0.2, 0.2});
    sfSprite_setScale(project->player->player_stats->
    move_range_image->sprite, (sfVector2f) {0.2, 0.2});
    sfSprite_setScale(project->player->player_stats->
    mana_image->sprite, (sfVector2f) {0.2, 0.2});
    sfRenderWindow_drawSprite(WINDOW, project->player->player_stats->
    health_image->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, project->player->player_stats->
    attack_image->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, project->player->player_stats->
    defense_image->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, project->player->player_stats->
    move_range_image->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, project->player->player_stats->
    mana_image->sprite, NULL);
}

void update_stats_ter(project_t *project, sfVector2f vect)
{
    sfSprite_setPosition(project->player->player_stats->attack_image->
    sprite, (sfVector2f) {vect.x - 50, vect.y - 17 + 4});
    sfSprite_setPosition(project->player->player_stats->defense_image->
    sprite, (sfVector2f) {vect.x - 50, vect.y - 17 + 8});
    sfSprite_setPosition(project->player->player_stats->health_image->
    sprite, (sfVector2f) {vect.x - 50, vect.y - 17 + 12});
    sfSprite_setPosition(project->player->player_stats->mana_image->
    sprite, (sfVector2f) {vect.x - 50, vect.y - 17 + 16});
    sfSprite_setPosition(project->player->player_stats->move_range_image->
    sprite, (sfVector2f) {vect.x - 50, vect.y - 17 + 20});
    update_stats_four(project);
}

void update_stats_bis(project_t *project, sfVector2f vect)
{
    sfText_setPosition(project->player->player_stats->attack_text,
    (sfVector2f) {vect.x - 42, vect.y - 17 + 4});
    sfText_setPosition(project->player->player_stats->defense_text,
    (sfVector2f) {vect.x - 42, vect.y - 17 + 8});
    sfText_setPosition(project->player->player_stats->health_text,
    (sfVector2f) {vect.x - 42, vect.y - 17 + 12});
    sfText_setPosition(project->player->player_stats->mana_text,
    (sfVector2f) {vect.x - 42, vect.y - 17 + 16});
    sfText_setPosition(project->player->player_stats->move_range_text,
    (sfVector2f) {vect.x - 42, vect.y - 17 + 20});
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->attack_text, NULL);
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->defense_text, NULL);
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->health_text, NULL);
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->mana_text, NULL);
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->move_range_text, NULL);
}

void update_stats(project_t *project)
{
    sfVector2f vect = {project->player->pos.x, project->player->pos.y};

    sfText_setString(project->player->player_stats->attack_text,
    int_to_str(project->player->player_stats->attack_value));
    sfText_setString(project->player->player_stats->defense_text,
    int_to_str(project->player->player_stats->defense_value));
    sfText_setString(project->player->player_stats->health_text,
    int_to_str(project->player->player_stats->health_value));
    sfText_setString(project->player->player_stats->mana_text,
    int_to_str(project->player->player_stats->mana_value));
    sfText_setString(project->player->player_stats->move_range_text,
    int_to_str(project->player->player_stats->move_range_value));
    update_stats_bis(project, vect);
    update_stats_ter(project, vect);
}
