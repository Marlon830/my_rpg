/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** fight_state.c
*/

#include "project.h"

void set_state_with_end_of_fight_four(project_t *project)
{
    if (!my_strcmp("/boat_guy.png", project->pnj_fighting)) {
        project->player->player_second_state = 4;
        finish_quest("SEC_QUETE4", project->quests);
        add_elem(project->inventory->bag,
        "assets/object/sword_gold.png", SWORD, 1);
        set_pnj_dialogue(project->scene->pnj, "/boat_guy.png", "Boat3");
        check_all_pnj_dialogue(project);
    }
}

void dungeon_quest_fight_bis(project_t *project)
{
    if (!my_strcmp("/therock.png", project->pnj_fighting)) {
        project->player->player_progress_state = 11;
        finish_quest("QUETE5", project->quests);
        add_quest("Trouver les crampter", project->quests,
        "QUETE6");
        add_elem(project->inventory->bag,
        "assets/object/amulet_ruby.png", AMULET, 1);
        set_pnj_dialogue(project->scene->pnj, "/therock.png", "Therock2");
        check_all_pnj_dialogue(project);
    }
}

void dungeon_quest_fight(project_t *project)
{
    if (!my_strcmp("/etchebest.png", project->pnj_fighting)) {
        project->player->player_progress_state = 7;
        set_pnj_dialogue(project->scene->pnj, "/etchebest.png", "Etchebest2");
        check_all_pnj_dialogue(project);
        add_quest("Combattre Heisenberg", project->quests,
        "QUETE4");
    }
    if (!my_strcmp("/heisenberg.png", project->pnj_fighting)) {
        project->player->player_progress_state = 9;
        finish_quest("QUETE4", project->quests);
        add_quest("Combattre The Rock", project->quests,
        "QUETE5");
        add_elem(project->inventory->bag,
        "assets/object/ring_gelano.png", RING, 1);
        set_pnj_dialogue(project->scene->pnj, "/heisenberg.png", "Heisenberg2");
        check_all_pnj_dialogue(project);
    }
    set_state_with_end_of_fight_four(project);
    dungeon_quest_fight_bis(project);
}

void tuto_fight_state(project_t *project)
{
    if (!my_strcmp("/theodore.png", project->pnj_fighting)) {
        project->player->player_progress_state = 4;
        add_elem(project->inventory->bag, "assets/object/pants_bronze.png",
        PANTS, 1);
        finish_quest("QUETE1", project->quests);
        add_quest("Visiter les environs", project->quests, "QUETE2");
        set_pnj_dialogue(project->scene->pnj, "/theodore.png",
        "Theoronfle5");
        check_all_pnj_dialogue(project);
    }
    if (!my_strcmp("/skull.png", project->pnj_fighting)) {
        project->player->player_progress_state = 5;
        finish_quest("QUETE2", project->quests);
        add_quest("Aller en ville", project->quests,
        "QUETE3");
        add_elem(project->inventory->bag,
        "assets/object/sword_silver.png", SWORD, 1);
        set_pnj_dialogue(project->scene->pnj, "/skull.png", "Skull3");
        check_all_pnj_dialogue(project);
    }
}

void set_state_with_end_of_fight(project_t *project)
{
    if (project->fight_win == 1) {
        tuto_fight_state(project);
        secondary_quest_fight_state(project);
        dungeon_quest_fight(project);
    }
}
