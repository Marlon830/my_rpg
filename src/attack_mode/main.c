/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myradar-edgar.maurel
** File description:
** main.c
*/

#include "attack_mode.h"


int main(int argc, char const *argv[])
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = NULL;
    window = sfRenderWindow_create(mode, "my_rpg",
    sfClose | sfResize | sfFullscreen, NULL);
    battle_scene_t *scene = create_battle_scene(30, 30,
    (sfVector2f){100, 500}, (sfVector2f){50, 25});
    sfEvent event;
    sfClock *clock = sfClock_create();
    float seconds;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, scene, scene->hand);
        }
        seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
        update_battle_scene(scene, seconds, window);
        sfRenderWindow_clear(window, (sfColor){20, 54, 66, 255});
        draw_batle_scene(scene, window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
