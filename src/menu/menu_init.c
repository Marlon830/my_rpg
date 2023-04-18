/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu_init.c
*/

#include "project.h"

slider_t *create_slider(sfVector2f pos, sfVector2f size, sfColor background)
{
    slider_t *slider = malloc(sizeof(slider_t));

    slider->rect = sfRectangleShape_create();
    slider->circle = sfCircleShape_create();
    slider->position = pos;
    slider->position_circle =
    (sfVector2f) {pos.x + size.x - 20, pos.y - size.y - 2};
    slider->size = size;
    slider->background = background;
    slider->foreground = sfWhite;
    slider->value = 100;
    sfCircleShape_setFillColor(slider->circle, sfWhite);
    sfCircleShape_setRadius(slider->circle, 10);
    sfCircleShape_setPosition(slider->circle, slider->position_circle);
    sfRectangleShape_setSize(slider->rect, size);
    sfRectangleShape_setFillColor(slider->rect, background);
    sfRectangleShape_setPosition(slider->rect, pos);
    return slider;
}

main_menu_t *init_main_menu_ter(main_menu_t *main_menu)
{
    main_menu->act_volume = create_text((sfVector2f) {1025, 400},
    (sfVector2f) {1, 1}, sfWhite);
    sfMusic_play(main_menu->music);
    sfMusic_setLoop(main_menu->music, sfTrue);
    main_menu->sound = sfSound_create();
    sfSoundBuffer *sound_buffer = sfSoundBuffer_createFromFile
    ("assets/music/soundbtn.ogg");
    sfSound_setBuffer(main_menu->sound, sound_buffer);
    main_menu->slider = create_slider((sfVector2f) {1100, 420},
    (sfVector2f) {300, 5}, sfBlack);
    main_menu->is_sliding = 0;
    return main_menu;
}

main_menu_t *init_main_menu_bis(main_menu_t *main_menu)
{
    main_menu->save = get_save();
    next_init_main_menu(main_menu);
    main_menu->fullscreen = create_button((sfVector2f){1025, 550},
    (sfVector2f) {420 / 2, 120 / 2}, "assets/UI/fullscreen/",
    &set_win_fullscreen);
    main_menu->windowed = create_button((sfVector2f)
    {1025 + (420 / 2) + 5, 550},
    (sfVector2f) {420 / 2, 120 / 2}, "assets/UI/windowed/", &set_win_windowed);
    main_menu->first_resolution = create_button((sfVector2f){1025, 700},
    (sfVector2f) {420 / 2, 120 / 2}, "assets/UI/resolution1/",
    &set_first_resolution);
    main_menu->second_resolution = create_button((sfVector2f)
    {1025 + (420 / 2) + 5, 700},
    (sfVector2f) {420 / 2, 120 / 2}, "assets/UI/resolution2/",
    &set_second_resolution);
    main_menu->music = sfMusic_createFromFile("assets/music/medietrap.ogg");
    return init_main_menu_ter(main_menu);
}

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
    main_menu->play = create_button((sfVector2f){425, 400},
    (sfVector2f){420, 120}, "assets/UI/play/", &display_play);
    main_menu->settings = create_button((sfVector2f){425, 550},
    (sfVector2f){420, 120}, "assets/UI/settings/", &display_settings);
    main_menu->quit = create_button((sfVector2f){425, 700},
    (sfVector2f){420, 120}, "assets/UI/quit/", &quit_button);
    main_menu->new_game = create_button((sfVector2f){1025, 400},
    (sfVector2f){420, 120}, "assets/UI/new_game/", &play_button);
    main_menu->load_game = create_button((sfVector2f){1025, 550},
    (sfVector2f){420, 120}, "assets/UI/load_game/", &play_button);
    return init_main_menu_bis(main_menu);
}
