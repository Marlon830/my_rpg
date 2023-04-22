/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_credit.c
*/

#include "project.h"

void destroy_credit(credit_t *credit)
{
    if (credit == NULL)
        return;
    if (credit->clock_credit != NULL)
        sfClock_destroy(credit->clock_credit);
    if (credit->font != NULL)
        sfFont_destroy(credit->font);
    if (credit->string != NULL)
        free(credit->string);
    if (credit->text != NULL)
        sfText_destroy(credit->text);
    free(credit);
}
