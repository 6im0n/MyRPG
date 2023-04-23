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
    [Q_MAIN_P1][TQ_TITLE] = "Save Willow - Chapter I",
    [Q_MAIN_P1][TQ_DESCRIPTION] = "Save your friend, you need to find \
the golden\nchalice",
    [Q_MAIN_P1][TQ_DETAIL] = "Main quests",
    [Q_MAIN_P1][TQ_OBJECTIF] = "Discover 2 ancient monuments",
    [Q_MAIN_P1][TQ_REWARD] = "Sword level 3",
    [Q_MAIN_P2][TQ_TITLE] = "Save Willow - Chapter II",
    [Q_MAIN_P2][TQ_DESCRIPTION] = "Save your friend, you need to find \
the golden\nchalice",
    [Q_MAIN_P2][TQ_DETAIL] = "Main quests",
    [Q_MAIN_P2][TQ_OBJECTIF] = "Kill 3 mobs",
    [Q_MAIN_P2][TQ_REWARD] = "Hammer level 4",
    [Q_MAIN_P3][TQ_TITLE] = "Save Willow - Chapter III",
    [Q_MAIN_P3][TQ_DESCRIPTION] = "Save your friend, you need to find \
the golden\nchalice",
    [Q_MAIN_P3][TQ_DETAIL] = "Main quests",
    [Q_MAIN_P3][TQ_OBJECTIF] = "Have 10 new levels",
    [Q_MAIN_P3][TQ_REWARD] = "Sword level 4",
    [Q_MAIN_P4][TQ_TITLE] = "Save Willow - Chapter IV",
    [Q_MAIN_P4][TQ_DESCRIPTION] = "Save your friend, you need to find \
the golden\nchalice",
    [Q_MAIN_P4][TQ_DETAIL] = "Main quests",
    [Q_MAIN_P4][TQ_OBJECTIF] = "Kill 15 mobs",
    [Q_MAIN_P4][TQ_REWARD] = "Spear level 4",
    [Q_SAVE][TQ_TITLE] = "Save",
    [Q_SAVE][TQ_DESCRIPTION] = "Save your game in order not to lose your \n\
progress",
    [Q_SAVE][TQ_DETAIL] = "It's very usefull !",
    [Q_SAVE][TQ_OBJECTIF] = "Find the blachsmith in order to save a game",
    [Q_SAVE][TQ_REWARD] = "30 XP",
    [Q_FINAL][TQ_TITLE] = "Save Willow - Chapter V",
    [Q_FINAL][TQ_OBJECTIF] = "Find a shrine ",
    [Q_FINAL][TQ_DESCRIPTION] = "Save your friend, you need to find \
the golden\nchalice",
    [Q_FINAL][TQ_DETAIL] = "Main quests",
    [Q_FINAL][TQ_REWARD] = "Golden Chalice",
};

static int quests_loaders_goal[Q_LEN] = {
    [Q_MAIN_P1] = 2,
    [Q_MAIN_P2] = 3,
    [Q_MAIN_P3] = 10,
    [Q_MAIN_P4] = 15,
    [Q_SAVE] = 1,
    [Q_FINAL] = 1
};

#endif /* !RESSOURCES_QUESTS_LOADERS_H */
