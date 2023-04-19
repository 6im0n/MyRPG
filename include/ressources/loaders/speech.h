/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** quests
*/

#ifndef RESSOURCES_SPEECH_LOADERS_H
    #define RESSOURCES_SPEECH_LOADERS_H

    #include "ressources/speech.h"

static char *speech_loaders[SP_LEN][SS_LEN] = {
    [SP_MAIN_QUESTS_1][SS_TITLE] = "Yann",
    [SP_MAIN_QUESTS_1][SS_SP] = "Ah... ah... you're here... finally...",
    [SP_MAIN_QUESTS_2][SS_TITLE] = "Yann",
    [SP_MAIN_QUESTS_2][SS_SP] = "I'm badly injured andI can't move to\n \
explore the surroundings.\nYou're going to have to help me.",
    [SP_MAIN_QUESTS_3][SS_TITLE] = "(Me)",
    [SP_MAIN_QUESTS_3][SS_SP] = "What happened? How did you get hurt?",
    [SP_MAIN_QUESTS_4][SS_TITLE] = "(Me)",
    [SP_MAIN_QUESTS_4][SS_SP] = "I've explored the surroundings quite a bit.\n\
I should go back and check on Yann.",
};

static int speech_loaders_timer[SP_LEN] = {
    [SP_MAIN_QUESTS_1] = 6,
    [SP_MAIN_QUESTS_2] = 8,
    [SP_MAIN_QUESTS_3] = 6,
    [SP_MAIN_QUESTS_4] = 6
};

#endif /* !RESSOURCES_SPEECH_LOADERS_H */
