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
    #include "attack_structs.h"
    #include "attack_mode.h"
    #include "credit.h"

    #define WINDOW project->window
    #define FOREST 0
    #define HOUSE 1
    #define DUNGEON 2

enum game_state {
    MAIN_MENU,
    GAME,
    FIGHT,
    PAUSE_MENU,
    CREDIT,
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
    pause_menu_t *pause_menu;
    sfEvent event;
    battle_scene_t *battle_scene;
    quest_t *quests;
    sfText *quests_button;
    sfVideoMode mode;
    float volume;
    int is_fullscreen;
    char *pnj_fighting;
    int fight_win;
    sfSoundBuffer *soundbuffer;
    sfSound *sound;
    credit_t *credit;
} project_t;

void update_scene(project_t *project);

list_t *create_all_dialogues(project_t *project, char *path_to_all_dialogue);
char *get_dialogue_by_id(project_t *project, list_t *dialogue, char *id);
char *get_dialogue_image(char *dialogue);
void display_dialogue(project_t *project, all_pnjs_t *act_pnj);
void change_view(project_t *project, sfView *camera,
sfVector2f size, sfVector2f pos);
all_pnjs_t *create_pnj(char *dial,
    sfFloatRect *pos_size, char *id);
void set_pnj_dialogue(list_t *all_pnj, char *pnj_id, char *dialogue_id);
void change_state_with_dialogue(project_t *project, all_pnjs_t *act_pnj);
void change_state_with_scene(project_t *project, int to_scene_id);
void set_all_pnj_dialogues(project_t *project);
void check_all_pnj_dialogue(project_t *project);
char *get_file(char *filepath);

void handle_end_of_fight(project_t *project);
void battle_scene_event(project_t *project);
void add_quest(char *quest_to_add, quest_t *quests, char *quest_id);
void update_quest(quest_t *quests);
quest_t *init_quests(void);
void finish_quest(char *quest_id, quest_t *quests);
void quest_draw(project_t *project);
void quest_event(project_t *project, sfEvent event);
player_t *init_player(int x, int y);
act_dial_t *init_actual_dialogue(void);
project_t *init_project(void);
equipment_t *init_equipment(void);
save_t *get_save(project_t *project);
void set_state_with_end_of_fight(project_t *project);
player_stats_t *init_stats(void);
char *get_info(char *str, int pos_word);

char *get_quest_name(char *buffer);
char *get_quest_id(char *buffer);
void get_quests(project_t *project, FILE *fp);
void save_quests(project_t *project, int fd);

void theoronfle_quest(project_t *project, all_pnjs_t *act_pnj);
void bed_quest(project_t *project, all_pnjs_t *act_pnj);
void kid_quest(project_t *project, all_pnjs_t *act_pnj);
void skull_quest(project_t *project, all_pnjs_t *act_pnj);
void door_quest(project_t *project, all_pnjs_t *act_pnj);
void chest_quest(project_t *project, all_pnjs_t *act_pnj);
void etchebest_quest(project_t *project, all_pnjs_t *act_pnj);
void mickey_quest(project_t *project, all_pnjs_t *act_pnj);
void client_quest(project_t *project, all_pnjs_t *act_pnj);
void play_sound(project_t *project, char *filepath);
void reset_view(project_t *project);
sfVector2f convert_mouse_window(sfRenderWindow *window, int x, int y);
void dungeon_door1_quest(project_t *project, all_pnjs_t *act_pnj);
void heisenberg_quest(project_t *project, all_pnjs_t *act_pnj);
void chest2_quest(project_t *project, all_pnjs_t *act_pnj);
void dungeon_door2_quest(project_t *project, all_pnjs_t *act_pnj);
void dungeon_door3_quest(project_t *project, all_pnjs_t *act_pnj);
void therock_quest(project_t *project, all_pnjs_t *act_pnj);
void kid_quest(project_t *project, all_pnjs_t *act_pnj);
void boat_quest(project_t *project, all_pnjs_t *act_pnj);
void secondary_quest_fight_state(project_t *project);
void creator_quest(project_t *project, all_pnjs_t *act_pnj);
void destroy_project(project_t *project);
void destroy_button(button_t *button);
void destroy_slider(slider_t *slider);
void destroy_dialogue(act_dial_t *actual_dial);
void destroy_quest(quest_t *quest);

#endif
