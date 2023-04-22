/*
** EPITECH PROJECT, 2022
** test_map
** File description:
** main.c
*/

#include "project.h"
#include "utils.h"

void scene_management_bis(project_t *project)
{
    if (project->status == CREDIT) {
        credit_event(project);
        update_credit(project, project->credit);
    }
}

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
        update_battle_scene(project->battle_scene, project, project->window);
        handle_end_of_fight(project);
    }
    scene_management_bis(project);
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
    sfSound_stop(project->sound);
    sfSound_destroy(project->sound);
    sfSoundBuffer_destroy(project->soundbuffer);
    sfMusic_stop(project->main_menu->music);
    sfMusic_destroy(project->main_menu->music);
    sfMusic_stop(project->main_menu->music_ingame);
    sfMusic_destroy(project->main_menu->music_ingame);
    sfMusic_stop(project->credit->music);
    sfMusic_destroy(project->credit->music);
    sfRenderWindow_destroy(project->window);
    destroy_project(project);
    free(project);
}

int main(void)
{
    project_t *project = init_project();

    srand(10);
    push_back(&project->scenes, "forest", get_map("forest"), SCENE);
    push_back(&project->scenes, "house", get_map("house"), SCENE);
    push_back(&project->scenes, "basement", get_map("basement"), SCENE);
    push_back(&project->scenes, "city", get_map("city"), SCENE);
    push_back(&project->scenes, "dungeon1", get_map("dungeon1"), SCENE);
    push_back(&project->scenes, "mickey", get_map("mickey_house"), SCENE);
    push_back(&project->scenes, "coiffeur", get_map("coiffeur"), SCENE);
    push_back(&project->scenes, "boat", get_map("boat"), SCENE);
    push_back(&project->scenes, "kid", get_map("kid"), SCENE);
    push_back(&project->scenes, "dungeon2", get_map("dungeon2"), SCENE);
    push_back(&project->scenes, "dungeon3", get_map("dungeon3"), SCENE);
    push_back(&project->scenes, "final_stage", get_map("final_stage"), SCENE);
    main_loop(project);
    return 0;
}
