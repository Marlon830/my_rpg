/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_sound.c
*/

#include "project.h"

void play_sound(project_t *project, char *filepath)
{
    if (project->soundbuffer != NULL)
        sfSoundBuffer_destroy(project->soundbuffer);
    project->soundbuffer = sfSoundBuffer_createFromFile(filepath);
    sfSound_setBuffer(project->sound, project->soundbuffer);
    sfSound_stop(project->sound);
    sfSound_play(project->sound);
}
