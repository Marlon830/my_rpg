/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** project.h
*/

#ifndef PROJECT_H_
    #define PROJECT_H_
    #include "scene.h"
    #include "utils.h"
    #include "inventory.h"
    #include "player.h"
    #include "menu.h"


    #define WINDOW project->window

enum game_state {
    MENU,
    GAME,
    FIGHT
};

typedef struct actual_dialogue_s {
    char *dialogue;
    int pos;
    sfText *text;
    sfRectangleShape *rect;
    int is_displayed;
    image_t *face;
} act_dial_t;

typedef struct all_pnjs_s {
    char *dial;
    sfFloatRect *hitbox;
    sfFloatRect *pos_size;
    image_t *sprite;
    int can_talk;
    char *name;
} all_pnjs_t;

typedef struct quest_s {
    int is_act_disp;
    list_t *actual_quests_list;
    list_t *finished_quests_list;
    sfRectangleShape *actual_quests_rect;
    sfRectangleShape *finished_quests_rect;
    sfText *actual_quests_text;
    sfText *finished_quests_text;
} quest_t;

typedef struct project_s {
    sfRenderWindow *window;
    inventory_t *inventory;
    scene_t *scene;
    sfClock *clock;
    list_t *all_dialogues;
    act_dial_t *actual_dial;
    float dt;
    player_t *player;
    int scene_id;
    enum game_state status;
    list_t *scenes;
    main_menu_t *main_menu;
    sfEvent event;
    quest_t *quests;
} project_t;

void update_scene(project_t *project);

list_t *create_all_dialogues(project_t *project, char *path_to_all_dialogue);
char *get_dialogue_by_id(project_t *project, list_t *dialogue, char *id);
char *get_dialogue_image(char *dialogue);
void display_dialogue(project_t *project);
void change_view(project_t *project, sfView *camera,
sfVector2f size, sfVector2f pos);
all_pnjs_t *create_pnj(char *dial,
    sfFloatRect *pos_size, char *id);
void set_pnj_dialogue(list_t *all_pnj, char *pnj_id, char *dialogue_id);
void change_state_with_dialogue(project_t *project);
void change_state_with_scene(project_t *project);
void set_all_pnj_dialogues(project_t *project);

void add_quest(char *quest_to_add, quest_t *quests, char *quest_id);
void update_quest(quest_t *quests);
quest_t *init_quests(void);
void finish_quest(char *quest_id, quest_t *quests);

#endif
