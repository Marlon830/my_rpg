/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_maneger.c
*/

#include "project.h"

sfBool is_button_clicked(button_t *button, sfMouseButtonEvent *evt)
{
    sfFloatRect res = sfRectangleShape_getGlobalBounds(button->rect);
    return sfFloatRect_contains(&res, evt->x, evt->y);
}

sfBool is_button_hover(button_t *button, sfMouseMoveEvent *evt)
{
    sfFloatRect res = sfRectangleShape_getGlobalBounds(button->rect);
    return sfFloatRect_contains(&res, evt->x, evt->y);
}

button_t *create_button(sfVector2f position , sfVector2f size,
char *path, void (*clicked)(project_t *project))
{
    button_t *button = malloc(sizeof(button_t));

    button->position = position;
    button->size = size;
    button->clicked = clicked;
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, button->position);
    sfRectangleShape_setSize(button->rect, button->size);
    button->sprite = sfSprite_create();
    sfSprite_setPosition(button->sprite, button->position);
    button->texture = sfTexture_createFromFile(my_strcat(path, "btn.png"),
    &(sfIntRect){0, 0, size.x, size.y});
    button->texture_hover = sfTexture_createFromFile(
    my_strcat(path, "btn_hover.png"), &(sfIntRect){0, 0, size.x, size.y});
    button->is_clicked = &is_button_clicked;
    button->update = &update_button;
    return button;
}

void update_hover_button(button_t *btn, sfVector2i mouse_pos)
{
    if (mouse_pos.x >= btn->position.x && mouse_pos.x <= btn->position.x
    + btn->size.x && mouse_pos.y >= btn->position.y && mouse_pos.y <=
    btn->position.y + btn->size.y)
        sfSprite_setTexture(btn->sprite, btn->texture_hover, sfFalse);
    else
        sfSprite_setTexture(btn->sprite, btn->texture, sfFalse);
}

void update_button(button_t *btn, project_t *project, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(WINDOW);

    if (event.type == sfEvtMouseButtonPressed) {
        if (btn->is_clicked(btn, &event.mouseButton))
            btn->clicked(project);
    }
    update_hover_button(btn, mouse_pos);
    sfRenderWindow_drawSprite(project->window, btn->sprite, NULL);
}
