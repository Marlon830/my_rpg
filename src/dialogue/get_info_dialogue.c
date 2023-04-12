/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** get_info_dialogue.c
*/

#include "project.h"

char *get_dialogue_image(char *dialogue)
{
    char *ans = malloc(sizeof(char) * my_strlen(dialogue));
    int i = 0;
    int j = 0;

    for (; dialogue[i] != ':'; i++);
    i++;
    for (; dialogue[i] != ':'; i++);
    i++;
    for (; dialogue[i] != '\n'; i++)
        ans[j++] = dialogue[i];
    ans[j] = '\0';
    return ans;
}

char *get_dialogue_by_id(project_t *project, list_t *dialogue, char *id)
{
    list_t *temp = dialogue;
    sfVector2f init_img = {0, 0};
    sfVector2f img_size = {220, 220};

    if (temp == NULL)
        return NULL;
    while (my_strcmp(temp->id, id) != 0) {
        temp = temp->next;
        if (temp == NULL)
            return NULL;
    }
    project->actual_dial->face = create_image(init_img,
    get_dialogue_image((char *) temp->element),
    (sfIntRect) {0, 0, 220, 220}, img_size);
    sfSprite_setScale(project->actual_dial->face->sprite,
    (sfVector2f) {0.13, 0.13});
    return (char *) temp->element;
}
