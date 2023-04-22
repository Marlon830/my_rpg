/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** fight_state_bis.c
*/

#include "project.h"

void secondary_quest_fight_state_bis(project_t *project)
{
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
    if (!my_strcmp("/kid.png", project->pnj_fighting)) {
        project->player->player_second_state = 3;
        finish_quest("SEC_QUETE3", project->quests);
        add_quest("Chercher un bateau", project->quests,
        "SEC_QUETE4");
        add_elem(project->inventory->bag,
        "assets/object/helmet_gold.png", HELMET, 1);
        set_pnj_dialogue(project->scene->pnj, "/kid.png", "Kid3");
        check_all_pnj_dialogue(project);
    }
}

void secondary_quest_fight_state(project_t *project)
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
    secondary_quest_fight_state_bis(project);
}
