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
char *txt, void (*clicked)(project_t *project))
{
    button_t *button = malloc(sizeof(button_t));
    button->rect = sfRectangleShape_create();
    button->position = position;
    button->size = size;
    button->color = sfBlack;
    button->txt_str = txt;
    button->clicked = clicked;
    button->text = create_text((sfVector2f){position.x + size.x / 6,
    position.y * 1.02}, (sfVector2f){1, 1}, sfWhite);
    sfText_setCharacterSize(button->text, 100);
    sfText_setString(button->text, button->txt_str);
    button->is_clicked = &is_button_clicked;
    button->update = &update_button;
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, button->color);
    return button;
}

void update_hover_button(button_t *btn, sfVector2i mouse_pos)
{
    if (mouse_pos.x >= btn->position.x && mouse_pos.x <= btn->position.x
    + btn->size.x && mouse_pos.y >= btn->position.y && mouse_pos.y <=
    btn->position.y + btn->size.y)
        sfRectangleShape_setFillColor(btn->rect, sfBlue);
    else
        sfRectangleShape_setFillColor(btn->rect, btn->color);
}

void update_button(button_t *btn, project_t *project, sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(WINDOW);

    if (event.type == sfEvtMouseButtonPressed) {
        if (btn->is_clicked(btn, &event.mouseButton))
            btn->clicked(project);
    }
    update_hover_button(btn, mouse_pos);
    sfRenderWindow_drawRectangleShape(project->window, btn->rect, NULL);
    sfRenderWindow_drawText(project->window, btn->text, NULL);
}
