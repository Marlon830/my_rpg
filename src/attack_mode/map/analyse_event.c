/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** analyse_event.c
*/

#include "attack_mode.h"

void analyse_events_two(sfEvent event, sfRenderWindow *window,
battle_scene_t *scene, hand_t *hand)
{
    if (event.type == sfEvtMouseButtonPressed)
        click_card(window, event, hand);
    if (event.type == sfEvtMouseButtonReleased)
        unclick_card(hand, scene);
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft)
        move_player(scene->player, scene->map->hovered_tile, scene);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
        save_map(scene->map, "map.txt");
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
        end_of_turn(scene->player, hand, scene);
}

void analyse_events(sfRenderWindow *window, sfEvent event,
battle_scene_t *scene, hand_t *hand)
{
    if (event.type == sfEvtResized)
        sfRenderWindow_setView(window, sfView_createFromRect((sfFloatRect)
        {0, 0, event.size.width, event.size.height}));
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseMoved) {
        update_map(window, scene->map, event);
        hover_card(window, event, hand);
    }
    analyse_events_two(event, window, scene, hand);
}
