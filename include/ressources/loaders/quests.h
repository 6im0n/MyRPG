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
    [Q_MAIN_P2][TQ_REWARD] = "Hammer level 4",
    [Q_SAVE][TQ_TITLE] = "Save",
    [Q_SAVE][TQ_DESCRIPTION] = "Save your game in order not to lose your \
progress",
    [Q_SAVE][TQ_DETAIL] = "It's very usefull !",
    [Q_SAVE][TQ_OBJECTIF] = "Find the blachsmith in order to save a game",
    [Q_SAVE][TQ_REWARD] = "30 XP",
};

static int quests_loaders_goal[Q_LEN] = {
    [Q_MAIN_P1] = 2,
    [Q_MAIN_P2] = 10,
    [Q_SAVE] = 1
};

#endif /* !RESSOURCES_QUESTS_LOADERS_H */
