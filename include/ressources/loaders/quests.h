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
    [Q_MAIN_P1][TQ_TITLE] = "Save Yann - Chapter I",
    [Q_MAIN_P1][TQ_DESCRIPTION] = "Save your friend, you need to find \
the golden\nchalice",
    [Q_MAIN_P1][TQ_DETAIL] = "Main quests",
    [Q_MAIN_P1][TQ_OBJECTIF] = "Discover 2 ancient monuments",
    [Q_MAIN_P1][TQ_REWARD] = "Sword level 3",
    [Q_MAIN_P2][TQ_TITLE] = "Save Yann - Chapter II",
    [Q_MAIN_P2][TQ_DESCRIPTION] = "Save your friend, you need to find \
the golden\nchalice",
    [Q_MAIN_P2][TQ_DETAIL] = "Main quests",
    [Q_MAIN_P2][TQ_OBJECTIF] = "Kill 10 mobs",
    [Q_MAIN_P2][TQ_REWARD] = "Hammer level 4"
};

static int quests_loaders_goal[Q_LEN] = {
    [Q_MAIN_P1] = 2,
    [Q_MAIN_P2] = 10,
};

#endif /* !RESSOURCES_QUESTS_LOADERS_H */
