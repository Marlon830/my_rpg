/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_dialogue.c
*/

#include "project.h"

char *get_png_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat sb;
    char *buffer;

    stat(filepath, &sb);
    buffer = malloc(sizeof(char) * sb.st_size + 1);
    read(fd, buffer, sb.st_size);
    return buffer;
}

char *create_filepath(char *dirpath, char *filepath)
{
    char *ans = malloc(sizeof(char) * my_strlen(dirpath) +
    my_strlen(filepath) + 1);
    int i = 0;
    int j = 0;

    while (dirpath[i] != '\0') {
        ans[i] = dirpath[i];
        i++;
    }
    ans[i++] = '/';
    while (filepath[j] != '\0')
        ans[i++] = filepath[j++];
    ans[i] = '\0';
    return ans;
}

char *get_dialogue_id(char *dialogue)
{
    char *ans = malloc(sizeof(char) * my_strlen(dialogue));
    int i = 0;
    int j = 0;

    for (; dialogue[i] != ':'; i++);
    i++;
    for (; dialogue[i] != '\n'; i++)
        ans[j++] = dialogue[i];
    ans[j] = '\0';
    return ans;
}

list_t *create_all_dialogues(project_t *project, char *dirpath)
{
    DIR *all_dialogues = opendir(dirpath);
    struct dirent *info_dir;
    char *pnj_file;

    project->all_dialogues = malloc(sizeof(list_t));
    project->all_dialogues = NULL;
    while (1) {
        info_dir = readdir(all_dialogues);
        if (info_dir == NULL)
            break;
        if (info_dir->d_name[0] == '.')
            continue;
        pnj_file = get_png_file(create_filepath(dirpath, info_dir->d_name));
        push_back(&(project->all_dialogues), get_dialogue_id(pnj_file),
        (char *) pnj_file, DIALOGUE);
    }
    return project->all_dialogues;
}
