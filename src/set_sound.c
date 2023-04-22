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
    if (project->player->player_progress_state == 13) {
        project->soundbuffer =
        sfSoundBuffer_createFromFile("assets/music/fart.ogg");
        project->player->player_progress_state = 14;
    } else {
        project->soundbuffer = sfSoundBuffer_createFromFile(filepath);
    }
    sfSound_setBuffer(project->sound, project->soundbuffer);
    sfSound_stop(project->sound);
    sfSound_play(project->sound);
}
