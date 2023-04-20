/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_stats.c
*/

#include "project.h"

void update_stats_five(project_t *project, sfVector2f vect)
{
    player_stats_t *player_stats = project->player->player_stats;

    sfText_setString(player_stats->attack_name, "Attaque");
    sfText_setString(player_stats->defense_name, "Defense");
    sfText_setString(player_stats->health_name, "Vie");
    sfText_setString(player_stats->mana_name, "Energie");
    sfText_setString(player_stats->move_range_name, "Deplacement");
    sfText_setPosition(player_stats->attack_name,
    (sfVector2f) {vect.x - 47, vect.y - 17 + 4});
    sfText_setPosition(player_stats->defense_name,
    (sfVector2f) {vect.x - 47, vect.y - 17 + 8});
    sfText_setPosition(player_stats->health_name,
    (sfVector2f) {vect.x - 47, vect.y - 17 + 12});
    sfText_setPosition(player_stats->mana_name,
    (sfVector2f) {vect.x - 47, vect.y - 17 + 16});
    sfText_setPosition(player_stats->move_range_name,
    (sfVector2f) {vect.x - 47, vect.y - 17 + 20});
    sfRenderWindow_drawText(WINDOW, player_stats->attack_name, NULL);
    sfRenderWindow_drawText(WINDOW, player_stats->defense_name, NULL);
    sfRenderWindow_drawText(WINDOW, player_stats->health_name, NULL);
}

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
    sprite, (sfVector2f) {vect.x - 51, vect.y - 17 + 4});
    sfSprite_setPosition(project->player->player_stats->defense_image->
    sprite, (sfVector2f) {vect.x - 51, vect.y - 17 + 8});
    sfSprite_setPosition(project->player->player_stats->health_image->
    sprite, (sfVector2f) {vect.x - 51, vect.y - 17 + 12});
    sfSprite_setPosition(project->player->player_stats->mana_image->
    sprite, (sfVector2f) {vect.x - 51, vect.y - 17 + 16});
    sfSprite_setPosition(project->player->player_stats->move_range_image->
    sprite, (sfVector2f) {vect.x - 51, vect.y - 17 + 20});
    update_stats_four(project);
}

void update_stats_bis(project_t *project, sfVector2f vect)
{
    sfText_setPosition(project->player->player_stats->attack_text_value,
    (sfVector2f) {vect.x - 27, vect.y - 17.5 + 4});
    sfText_setPosition(project->player->player_stats->defense_text_value,
    (sfVector2f) {vect.x - 27, vect.y - 17.5 + 8});
    sfText_setPosition(project->player->player_stats->health_text_value,
    (sfVector2f) {vect.x - 27, vect.y - 17.5 + 12});
    sfText_setPosition(project->player->player_stats->mana_text_value,
    (sfVector2f) {vect.x - 27, vect.y - 17.5 + 16});
    sfText_setPosition(project->player->player_stats->move_range_text_value,
    (sfVector2f) {vect.x - 27, vect.y - 17.5 + 20});
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->attack_text_value, NULL);
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->defense_text_value, NULL);
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->health_text_value, NULL);
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->mana_text_value, NULL);
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->move_range_text_value, NULL);
}

void update_stats(project_t *project)
{
    sfVector2f vect = {project->player->pos.x, project->player->pos.y};

    sfText_setString(project->player->player_stats->attack_text_value,
    int_to_str(project->player->player_stats->attack_value));
    sfText_setString(project->player->player_stats->defense_text_value,
    int_to_str(project->player->player_stats->defense_value));
    sfText_setString(project->player->player_stats->health_text_value,
    int_to_str(project->player->player_stats->health_value));
    sfText_setString(project->player->player_stats->mana_text_value,
    int_to_str(project->player->player_stats->mana_value));
    sfText_setString(project->player->player_stats->move_range_text_value,
    int_to_str(project->player->player_stats->move_range_value));
    update_stats_bis(project, vect);
    update_stats_ter(project, vect);
    update_stats_five(project, vect);
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->mana_name, NULL);
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->move_range_name, NULL);
}
