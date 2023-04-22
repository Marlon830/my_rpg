/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_card_overlay.c
*/

#include "attack_mode.h"

void setup_overlay_text(sfText *text, sfVector2f pos, float angle)
{
    sfText_setRotation(text, 0);
    sfText_rotate(text, angle);
    sfText_setPosition(text, pos);
}

void setup_overlay_sprite(sprite_t *sprite, sfVector2f pos, float angle)
{
    sfSprite_setRotation(sprite->sprite, 0);
    sfSprite_rotate(sprite->sprite, angle);
    sfSprite_setPosition(sprite->sprite, pos);
}

void update_card_overlay(card_overlay_t *overlay, card_t *card)
{
    sfVector2f p1 = sfVertexArray_getVertex(card->array, 2)->position;
    sfVector2f p2 = sfVertexArray_getVertex(card->array, 7)->position;
    sfVector2f p3 = sfVertexArray_getVertex(card->array, 6)->position;
    sfVector2f p4 = sfVertexArray_getVertex(card->array, 6)->position;
    p1 = (sfVector2f){p1.x - (my_strlen((char *)
    sfText_getString(overlay->name))) * 33, p1.y - 2.5 * card->angle};
    p2 = (sfVector2f){p2.x + 10, p2.y};
    p3 = (sfVector2f){p3.x - 30, p3.y};
    p4 = (sfVector2f){p4.x - 20 -
    my_strlen((char *)sfText_getString(overlay->name)) * 2, p4.y + 30};
    setup_overlay_text(overlay->name, p1, card->angle);
    setup_overlay_text(overlay->damage, p2, card->angle);
    setup_overlay_text(overlay->energy, p3, card->angle);
    setup_overlay_text(overlay->range, p4, card->angle);
    setup_overlay_sprite(overlay->damage_sprite, (sfVector2f)
    {p2.x + 30, p2.y}, card->angle);
    setup_overlay_sprite(overlay->energy_sprite, (sfVector2f)
    {p3.x - 30, p3.y + 10}, card->angle);
    setup_overlay_sprite(overlay->range_sprite, (sfVector2f)
    {p4.x - 30, p4.y + 10}, card->angle);
}
