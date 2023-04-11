/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inventory.h
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <stdbool.h>

typedef struct box_s {
    sfRectangleShape *shape;
    sfVector2f pos_box;
    sfVector2f pos_sprite;
    sfSprite *sprite;
    sfTexture *texture;
    sfText *text;
} box_t;

typedef struct list_box_s {
    box_t *box;
    struct list_box_s *next;
} list_box_t;

typedef struct inventory_s {
    sfRectangleShape *shape;
    list_box_t *first_equipment;
    list_box_t *second_equipment;
    list_box_t *bag;
    box_t *character;
    box_t *description;
    bool is_active;
} inventory_t;

inventory_t *create_inventory(void);
void switch_state_inventory(inventory_t *inventory);
void update_inventory(project_t *project);

#endif
