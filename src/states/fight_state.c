/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** fight_state.c
*/

#include "project.h"

void set_state_with_end_of_fight_ter(project_t *project)
{
    if (!my_strcmp("/mickey.png", project->pnj_fighting)) {
        project->player->player_second_state = 1;
        finish_quest("SEC_QUETE1", project->quests);
        add_quest("Aller au salon de Quoi ? Feur", project->quests,
        "SEC_QUETE2");
        add_elem(project->inventory->bag,
        "assets/object/shield_gold.png", SHIELD, 1);
        set_pnj_dialogue(project->scene->pnj, "/mickey.png", "Mickey2");
        check_all_pnj_dialogue(project);
    }
    if (!my_strcmp("/client.png", project->pnj_fighting)) {
        project->player->player_second_state = 2;
        finish_quest("SEC_QUETE2", project->quests);
        add_quest("Chercher un T.U.R.C", project->quests,
        "SEC_QUETE3");
        add_elem(project->inventory->bag,
        "assets/object/armor_gold.png", ARMOR, 1);
        set_pnj_dialogue(project->scene->pnj, "/client.png", "Client3");
        check_all_pnj_dialogue(project);
    }
}

void set_state_with_end_of_fight_bis(project_t *project)
{
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
    if (!my_strcmp("/enemy.png", project->pnj_fighting)) {
        project->player->player_progress_state = 7;
        set_pnj_dialogue(project->scene->pnj, "/enemy.png", "Enemy2");
        check_all_pnj_dialogue(project);
        add_quest("Combattre Heisenberg", project->quests,
        "QUETE4");
    }
    set_state_with_end_of_fight_ter(project);
}

void set_state_with_end_of_fight(project_t *project)
{
    if (project->fight_win == 1) {
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
        set_state_with_end_of_fight_bis(project);
    }
}
