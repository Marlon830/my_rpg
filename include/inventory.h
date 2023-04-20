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

typedef struct player_s player_t;

enum inventory_state {
    NONE2 = 0,
    PRESSED,
};

enum object_type {
    NO_OBJECT = 0,
    OTHER,
    HELMET,
    ARMOR,
    PANTS,
    BOOTS,
    AMULET,
    RING,
    SWORD,
    SHIELD,
};

typedef struct box_s {
    sfRectangleShape *shape;
    sfVector2f pos_sprite;
    sfSprite *sprite;
    sfTexture *sprite_texture;
    sfTexture *box_texture;
    sfTexture *special_texture;
    bool is_special;
    sfSprite *hover;
    sfTexture *hover_texture;
    char *name;
    sfText *text;
    sfFont *font;
    float more_x;
    float more_y;
    int quantity;
    bool is_selected;
    int pos_animation;
    int max_animation;
    sfClock *clock_box;
    sfTime time_box;
    float seconds_box;
    enum object_type type_sprite;
    enum object_type type_box;
} box_t;

typedef struct list_box_s {
    box_t *box;
    struct list_box_s *next;
} list_box_t;

typedef struct inventory_s {
    sfRectangleShape *shape;
    sfTexture *texture;
    list_box_t *first_equipment;
    list_box_t *second_equipment;
    list_box_t *bag;
    box_t *character;
    box_t *description;
    bool is_active;
    enum inventory_state state;
    bool box_selected;
    bool shift_pressed;
} inventory_t;

inventory_t *create_inventory(void);
list_box_t *init_list_box(void);
box_t *get_box_with_name(list_box_t *list, char *name);
box_t *get_box_with_coord(project_t *project, sfVector2f pos);
box_t *get_box_selected(project_t *project);
box_t *get_box_with_type(inventory_t *inventory, enum object_type type);
box_t *get_empty_box(inventory_t *inventory);
sfVector2f convert_mouse_position(project_t *project, sfVector2f pos);

void add_box_to_list(list_box_t *list, box_t *box);
void switch_state_inventory(inventory_t *inventory);
bool add_elem(list_box_t *list, char *name, int type, int quantity);
void delete_elem(list_box_t *list, char *name, int quantity);
void update_inventory(project_t *project);
void select_box(project_t *project, sfVector2f pos);
void unselect_box(project_t *project, sfVector2f pos);
void add_new_elem_in_box(box_t *box, char *name, int type, int quantity);
void reset_box(box_t *box);
void update_selected_box(project_t *project);
void create_box_des_char(box_t *box, int des_char);
void update_inventory_character(project_t *project, box_t *box);
void update_inventory_description(project_t *project, box_t *box);
void update_description(project_t *project, inventory_t *inventory, box_t *box);
void update_hover_or_selected_box(project_t *project, box_t *box);
void update_equipment_inventory_sprite(project_t *project, box_t *character,
player_t *player);
void modify_type_box(inventory_t *inventory);
void change_elem_box(project_t *project, box_t *new_box, box_t *selected_box);
void switch_elem_box(project_t *project, box_t *new_box, box_t *selected_box);
int check_shift_click(project_t *project, box_t *box);
int get_good_path(char *name);
void destroy_inventory(inventory_t *inventory);
void switch_stat(project_t *project, box_t *box, box_t *box2);
void add_or_delete_stat(project_t *project, box_t *new_box,
box_t *selected_box);

#endif
