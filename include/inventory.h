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

enum inventory_state {
    NONE = 0,
    PRESSED,
};

typedef struct box_s {
    sfRectangleShape *shape;
    sfVector2f pos_sprite;
    sfSprite *sprite;
    sfTexture *sprite_texture;
    sfTexture *box_texture;
    char *name;
    sfText *text;
    sfFont *font;
    float more_x;
    float more_y;
    int quantity;
    bool is_selected;
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
    enum inventory_state state;
} inventory_t;

inventory_t *create_inventory(void);
list_box_t *init_list_box(void);
box_t *get_box_with_name(list_box_t *list, char *name);
box_t *get_box_with_coord(project_t *project, sfVector2f pos);
box_t *get_box_selected(project_t *project);
sfVector2f convert_mouse_position(project_t *project, sfVector2f pos);
void add_box_to_list(list_box_t *list, box_t *box);
void switch_state_inventory(inventory_t *inventory);
bool add_elem(list_box_t *list, char *name, int quantity);
void delete_elem(list_box_t *list, char *name, int quantity);
void update_inventory(project_t *project);
void select_box(project_t *project, sfVector2f pos);
void unselect_box(project_t *project, sfVector2f pos);
void add_new_elem_in_box(box_t *box, char *name, int quantity);
void reset_box(box_t *box);
void update_selected_box(project_t *project);

#endif
