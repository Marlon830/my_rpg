/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button_maneger.c
*/

#include "project.h"

sfBool is_button_clicked(project_t *project, button_t *button,
sfMouseButtonEvent *evt)
{
    sfFloatRect res = sfRectangleShape_getGlobalBounds(button->rect);
    sfVector2i mouse = (sfVector2i) {evt->x, evt->y};
    sfView *view = sfView_create();
    sfView_setSize(view, (sfVector2f) {1920, 1080});
    sfView_setCenter(view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(WINDOW, mouse, view);

    return sfFloatRect_contains(&res, pos.x, pos.y);
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
    button->texture = sfTexture_createFromFile
    (my_strcat(path, "btn.png"), NULL);
    button->texture_hover = sfTexture_createFromFile(
    my_strcat(path, "btn_hover.png"), NULL);
    button->is_clicked = &is_button_clicked;
    button->update = &update_button;
    sfRectangleShape_setTexture(button->rect, button->texture, sfTrue);
    return button;
}

void update_hover_button(project_t *project, button_t *btn,
sfVector2i mouse_pos)
{
    sfView *view = sfView_create();
    sfView_setSize(view, (sfVector2f) {1920, 1080});
    sfView_setCenter(view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(WINDOW, mouse_pos, view);

    if (pos.x >= btn->position.x && pos.x <= btn->position.x
    + btn->size.x && pos.y >= btn->position.y && pos.y <=
    btn->position.y + btn->size.y)
        sfRectangleShape_setTexture(btn->rect, btn->texture_hover, sfTrue);
    else
        sfRectangleShape_setTexture(btn->rect, btn->texture, sfTrue);
}

void update_button(button_t *btn, project_t *project)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(WINDOW);

    update_hover_button(project, btn, mouse_pos);
    sfRenderWindow_drawRectangleShape(WINDOW, btn->rect, NULL);
}
