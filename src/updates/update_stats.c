/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_stats.c
*/

#include "project.h"

void update_stats_five(project_t *project, sfVector2f vect, sfVector2f scale)
{
    player_stats_t *player_stats = project->player->player_stats;

    sfText_setString(player_stats->attack_name, "Attaque");
    sfText_setString(player_stats->defense_name, "Defense");
    sfText_setString(player_stats->health_name, "Vie");
    sfText_setString(player_stats->mana_name, "Energie");
    sfText_setString(player_stats->move_range_name, "Deplacement");
    sfText_setPosition(player_stats->attack_name,
    (sfVector2f) {vect.x - 235 * scale.x, vect.y - 65 * scale.y});
    sfText_setPosition(player_stats->defense_name,
    (sfVector2f) {vect.x - 235 * scale.x, vect.y - 45 * scale.y});
    sfText_setPosition(player_stats->health_name,
    (sfVector2f) {vect.x - 235 * scale.x, vect.y - 25 * scale.y});
    sfText_setPosition(player_stats->mana_name,
    (sfVector2f) {vect.x - 235 * scale.x, vect.y - 5 * scale.y});
    sfText_setPosition(player_stats->move_range_name,
    (sfVector2f) {vect.x - 235 * scale.x, vect.y + 15 * scale.y});
    sfRenderWindow_drawText(WINDOW, player_stats->attack_name, NULL);
    sfRenderWindow_drawText(WINDOW, player_stats->defense_name, NULL);
    sfRenderWindow_drawText(WINDOW, player_stats->health_name, NULL);
}

void update_stats_four(project_t *project, sfVector2f scale)
{
    sfSprite_setScale(project->player->player_stats->
    health_image->sprite, scale);
    sfSprite_setScale(project->player->player_stats->
    attack_image->sprite, scale);
    sfSprite_setScale(project->player->player_stats->
    defense_image->sprite, scale);
    sfSprite_setScale(project->player->player_stats->
    move_range_image->sprite, scale);
    sfSprite_setScale(project->player->player_stats->
    mana_image->sprite, scale);
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

void update_stats_ter(project_t *project, sfVector2f vect, sfVector2f scale)
{
    sfSprite_setPosition(project->player->player_stats->attack_image->
    sprite, (sfVector2f) {vect.x - 255 * scale.x, vect.y - 65 * scale.y});
    sfSprite_setPosition(project->player->player_stats->defense_image->
    sprite, (sfVector2f) {vect.x - 255 * scale.x, vect.y - 45 * scale.y});
    sfSprite_setPosition(project->player->player_stats->health_image->
    sprite, (sfVector2f) {vect.x - 255 * scale.x, vect.y - 25 * scale.y});
    sfSprite_setPosition(project->player->player_stats->mana_image->
    sprite, (sfVector2f) {vect.x - 255 * scale.x, vect.y - 5 * scale.y});
    sfSprite_setPosition(project->player->player_stats->move_range_image->
    sprite, (sfVector2f) {vect.x - 255 * scale.x, vect.y + 15 * scale.y});
    update_stats_four(project, scale);
}

void update_stats_bis(project_t *project, sfVector2f vect, sfVector2f scale)
{
    sfText_setPosition(project->player->player_stats->attack_text_value,
    (sfVector2f) {vect.x - 135 * scale.x, vect.y - 67.5 * scale.y});
    sfText_setPosition(project->player->player_stats->defense_text_value,
    (sfVector2f) {vect.x - 135 * scale.x, vect.y - 47.5 * scale.y});
    sfText_setPosition(project->player->player_stats->health_text_value,
    (sfVector2f) {vect.x - 135 * scale.x, vect.y - 27.5 * scale.y});
    sfText_setPosition(project->player->player_stats->mana_text_value,
    (sfVector2f) {vect.x - 135 * scale.x, vect.y - 7.5 * scale.y});
    sfText_setPosition(project->player->player_stats->move_range_text_value,
    (sfVector2f) {vect.x - 135 * scale.x, vect.y + 12.5 * scale.y});
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

void update_stats(project_t *project, sfVector2f vect, sfVector2f scale)
{
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
    update_stats_bis(project, vect, scale);
    update_stats_ter(project, vect, scale);
    update_stats_five(project, vect, scale);
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->mana_name, NULL);
    sfRenderWindow_drawText(WINDOW,
    project->player->player_stats->move_range_name, NULL);
}
