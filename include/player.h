/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player.h
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include "utils.h"

enum player_state {
    IDLE_DOWN,
    IDLE_UP,
    IDLE_LEFT,
    IDLE_RIGHT,
    RUN_DOWN,
    RUN_UP,
    RUN_LEFT,
    RUN_RIGHT
};

typedef struct equipment_s {
    sfSprite *helmet;
    sfTexture *helmet_texture;
    sfSprite *armor;
    sfTexture *armor_texture;
    sfSprite *pants;
    sfTexture *pants_texture;
    sfSprite *boots;
    sfTexture *boots_texture;
    sfSprite *amulet;
    sfTexture *amulet_texture;
    sfSprite *ring;
    sfTexture *ring_texture;
    sfSprite *sword;
    sfTexture *sword_texture;
    sfSprite *shield;
    sfTexture *shield_texture;
} equipment_t;

typedef struct player_stats_s {
    int health_value;
    int attack_value;
    int defense_value;
    int move_range_value;
    int mana_value;
    sfText *health_text;
    sfText *attack_text;
    sfText *defense_text;
    sfText *move_range_text;
    sfText *mana_text;
    image_t *health_image;
    image_t *attack_image;
    image_t *defense_image;
    image_t *move_range_image;
    image_t *mana_image;
} player_stats_t;

typedef struct player_s {
    sfVector2f pos;
    sfFloatRect *col;
    float speed;
    enum player_state state;
    sfVector2f move;
    int player_progress_state;
    int player_second_state;
    equipment_t *equipment;
    image_t *character;
    player_stats_t *player_stats;
} player_t;

void modify_helmet(player_t *player, char *path);
void modify_armor(player_t *player, char *path);
void modify_pants(player_t *player, char *path);
void modify_boots(player_t *player, char *path);
void modify_amulet(player_t *player, char *path);
void modify_ring(player_t *player, char *path);
void modify_sword(player_t *player, char *path);
void modify_shield(player_t *player, char *path);
void draw_equipment(project_t *project, player_t *player);
void update_equipment(project_t *project, inventory_t *inventory);
void update_stats(project_t *project);
void destroy_equipment(equipment_t *equipment);

#endif
