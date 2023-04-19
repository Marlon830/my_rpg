/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** main.c
*/

#include "project.h"
#include "utils.h"

void scene_management(project_t *project)
{
    if (project->status == GAME) {
        sfRenderWindow_setView(project->window, project->scene->camera);
        scene_event(project);
        update_scene(project);
    }
    if (project->status == MAIN_MENU) {
        main_menu_event(project);
        draw_main_menu(project);
    }
    if (project->status == PAUSE_MENU) {
        pause_menu_event(project);
        draw_pause_menu(project);
    }
    if (project->status == FIGHT) {
        battle_scene_event(project);
        update_battle_scene(project->battle_scene, 0, project->window);
        handle_end_of_fight(project);
    }
}

void main_loop(project_t *project)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
        scene_management(project);
        sfRenderWindow_display(project->window);
    }
    scene_destroy(project->scene);
    sfSound_stop(project->main_menu->sound);
    sfSound_destroy(project->main_menu->sound);
    sfSoundBuffer_destroy(project->main_menu->soundbuffer);
    sfMusic_stop(project->main_menu->music);
    sfMusic_destroy(project->main_menu->music);
    sfRenderWindow_destroy(project->window);
    free(project);
}

int main(void)
{
    project_t *project = init_project();

    push_back(&project->scenes, "forest", get_map("forest"), SCENE);
    push_back(&project->scenes, "house", get_map("house"), SCENE);
    push_back(&project->scenes, "dungeon", get_map("dungeon"), SCENE);
    push_back(&project->scenes, "city", get_map("city"), SCENE);
    main_loop(project);
    return 0;
}
