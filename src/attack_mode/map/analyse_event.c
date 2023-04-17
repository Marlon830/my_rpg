/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** analyse_event.c
*/

#include "attack_mode.h"

void analyse_events_two(sfEvent event,
battle_scene_t *scene, hand_t *hand)
{
    if (event.type == sfEvtMouseButtonPressed)
        click_card(event, hand);
    if (event.type == sfEvtMouseButtonReleased)
        unclick_card(hand, scene);
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft)
        move_player(scene->player, scene->map->hovered_tile, scene->map, scene);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS)
        save_map(scene->map);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
        end_of_turn(scene->player, hand);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyC)
        add_card_to_hand(hand, "card", 10, 5);
}

void analyse_events(sfRenderWindow *window, sfEvent event,
battle_scene_t *scene, hand_t *hand)
{
    if (event.type == sfEvtResized)
        sfRenderWindow_setView(window, sfView_createFromRect((sfFloatRect)
        {0, 0, event.size.width, event.size.height}));
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseMoved) {
        update_map(scene->map, event);
        hover_card(event, hand);
    }
    analyse_events_two(event, scene, hand);
}
