/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu_init.c
*/

#include "project.h"

save_t *get_save(void)
{
    save_t *save = malloc(sizeof(save_t));
    save->pos = (sfVector2f){0, 0};
    FILE *fp = fopen("save", "r");
    size_t len = 0;
    char *line = NULL;

    getline(&line, &len, fp);
    if (line[0] == 'R') {
        free(save);
        return NULL;
    }
    save->scene_id = my_getnbr(line);
    getline(&line, &len, fp);
    save->pos.x = my_getnbr(line);
    for (; line[0] != ' '; line++);
    save->pos.y = my_getnbr(line);
    getline(&line, &len, fp);
    save->player_state = my_getnbr(line);
    fclose(fp);
    return save;
}

pause_menu_t *init_pause_menu(project_t *project)
{
    pause_menu_t *pause_menu = malloc(sizeof(pause_menu_t));
    pause_menu->camera = sfView_create();
    change_view(project, pause_menu->camera, (sfVector2f){1920, 1080},
    (sfVector2f){1920 / 2, 1080 / 2});
    pause_menu->background = create_image((sfVector2f){0, 0},
    "background.png", (sfIntRect){0, 0, 1920, 1080},
    (sfVector2f){1920, 1080});
    pause_menu->background->nb_sprite = 1;
    pause_menu->state = NAUNE;
    pause_menu->resume = create_button((sfVector2f){425, 350},
    (sfVector2f){420, 120}, "assets/UI/continue/", &resume_button);
    pause_menu->save = create_button((sfVector2f){425, 500},
    (sfVector2f){420, 120}, "assets/UI/save/", &new_save);
    pause_menu->settings = create_button((sfVector2f){425, 650},
    (sfVector2f){420, 120}, "assets/UI/settings/", &display_settings);
    pause_menu->back_menu = create_button((sfVector2f){425, 800},
    (sfVector2f){420, 120}, "assets/UI/back_menu/", &back_menu_button);
    return pause_menu;
}

void next_init_main_menu(main_menu_t *main_menu)
{
    main_menu->play = create_button((sfVector2f){425, 400},
    (sfVector2f){420, 120}, "assets/UI/play/", &display_play);
    main_menu->settings = create_button((sfVector2f){425, 550},
    (sfVector2f){420, 120}, "assets/UI/settings/", &display_settings);
    main_menu->quit = create_button((sfVector2f){425, 700},
    (sfVector2f){420, 120}, "assets/UI/quit/", &quit_button);
    main_menu->new_game = create_button((sfVector2f){1025, 400},
    (sfVector2f){420, 120}, "assets/UI/new_game/", &new_game_button);
    main_menu->load_game = create_button((sfVector2f){1025, 550},
    (sfVector2f){420, 120}, "assets/UI/load_game/", &load_game_button);
}

main_menu_t *init_main_menu(project_t *project)
{
    main_menu_t *main_menu = malloc(sizeof(main_menu_t));
    main_menu->camera = sfView_create();
    change_view(project, main_menu->camera, (sfVector2f){1920, 1080},
    (sfVector2f){1920 / 2, 1080 / 2});
    main_menu->background = create_image((sfVector2f){0, 0},
    "background.png", (sfIntRect){0, 0, 1920, 1080},
    (sfVector2f){1920, 1080});
    main_menu->background->nb_sprite = 1;
    main_menu->state = NAUNE;
    main_menu->save = get_save();
    next_init_main_menu(main_menu);
    return main_menu;
}
