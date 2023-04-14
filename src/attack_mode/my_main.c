/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_main.c
*/

#include "attack_mode.h"

int my_main(int argc, char **argv)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = NULL;
    window = sfRenderWindow_create(mode, "my_rpg",
    sfClose | sfResize | sfFullscreen, NULL);
    battle_scene_t *scene = create_battle_scene(30, 30,
    (sfVector2f){100, 500}, (sfVector2f){50, 25});
    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, scene, scene->hand);
        update_battle_scene(scene, 0, window);
        sfRenderWindow_clear(window, (sfColor){20, 54, 66, 255});
        draw_batle_scene(scene, window);
        sfRenderWindow_display(window);
        if (scene->win) {
            destroy_battle_scene(scene);
            break;
        }
    }
    sfRenderWindow_destroy(window);
}
