/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** quests
*/

#ifndef RESSOURCES_QUESTS_LOADERS_H
    #define RESSOURCES_QUESTS_LOADERS_H

    #include "ressources/quests.h"

static char *quests_loaders[Q_LEN][TQ_LEN] = {
    [Q_MAIN_P1][TQ_TITLE] = "Save Yann",
    [Q_MAIN_P1][TQ_DESCRIPTION] = "Save your friend, you need to find\
    the golden chalice",
    [Q_MAIN_P1][TQ_DETAIL] = "Near your spawn",
    [Q_MAIN_P1][TQ_OBJECTIF] = "Discover 2 ancient monuments",
    [Q_MAIN_P1][TQ_REWARD] = "Sword level 3"
};

#endif /* !RESSOURCES_QUESTS_LOADERS_H */
