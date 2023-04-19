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
    [SP_MAIN_QUESTS_1][SS_TITLE] = "TITLE",
    [SP_MAIN_QUESTS_1][SS_SP] = "PARAGRAPHE",
    [SP_MAIN_QUESTS_2][SS_TITLE] = "TITLE [2]",
    [SP_MAIN_QUESTS_2][SS_SP] = "TITLE [2]"
};

#endif /* !RESSOURCES_SPEECH_LOADERS_H */
