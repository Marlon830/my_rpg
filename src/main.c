/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** main.c
*/

#include "project.h"
#include "utils.h"

void main_loop(project_t *project)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
        scene_event(project);
        update_scene(project);
        sfRenderWindow_display(project->window);
    }
    scene_destroy(project->scene);
    sfRenderWindow_destroy(project->window);
    free(project);
}

player_t *init_player(int x, int y)
{
    player_t *player = malloc(sizeof(player_t));

    player->col = malloc(sizeof(sfFloatRect));
    player->pos.x = x;
    player->pos.y = y;
    player->col->left = player->pos.x;
    player->col->top = player->pos.y;
    player->col->width = 16;
    player->col->height = 8;
    player->speed = 1;
    player->move = (sfVector2f) {0, 0};
    player->state = IDLE_DOWN;
    return player;
}

act_dial_t *init_actual_dialogue(void)
{
    act_dial_t *actual_dial = malloc(sizeof(act_dial_t));

    actual_dial->pos = 0;
    actual_dial->text = create_text();
    actual_dial->rect = create_rect();
    actual_dial->is_displayed = 0;
    return actual_dial;
}

project_t *init_project(void)
{
    project_t *project = malloc(sizeof(project_t));
    sfVideoMode mode = (sfVideoMode){1920, 1080, 32};

    project->inventory = create_inventory();
    project->window = sfRenderWindow_create(mode, "Quoi ? Feur",
    sfClose | sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(project->window, 60);
    sfRenderWindow_setKeyRepeatEnabled(project->window, sfFalse);
    project->clock = sfClock_create();
    project->player = init_player(160, 160);
    project->scenes = NULL;
    project->scene = NULL;
    project->scene = load_scene(project, 0);
    project->actual_dial = init_actual_dialogue();
    project->all_dialogues = create_all_dialogues(project, "assets/dialogues");
    return project;
}

int main(void)
{
    project_t *project = init_project();
    push_back(&project->scenes, "island", get_map(project, "island"), SCENE);
    push_back(&project->scenes, "house", get_map(project, "house"), SCENE);
    push_back(&project->scenes, "sus", get_map(project, "sus"), SCENE);
    project->scene = load_scene(project, 0);
    main_loop(project);
    return 0;
}
