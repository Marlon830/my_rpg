/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_sound.c
*/

#include "project.h"

void play_sound(project_t *project, char *filepath)
{
    project->soundbuffer = sfSoundBuffer_createFromFile(filepath);
    sfSound_setBuffer(project->sound, project->soundbuffer);
    sfSound_stop(project->sound);
    sfSound_play(project->sound);
}
