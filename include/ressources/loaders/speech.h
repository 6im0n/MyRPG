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
    [SP_MAIN_QUESTS_1_1][SS_TITLE] = "Willow",
    [SP_MAIN_QUESTS_1_1][SS_SP] = "Ah... ah... you're here... finally...",
    [SP_MAIN_QUESTS_1_2][SS_TITLE] = "Willow",
    [SP_MAIN_QUESTS_1_2][SS_SP] = "I'm badly injured and I can't move to\n \
explore the surroundings.\nYou're going to have to help me.",
    [SP_MAIN_QUESTS_1_3][SS_TITLE] = "(Me)",
    [SP_MAIN_QUESTS_1_3][SS_SP] = "What happened? How did you get hurt?",
    [SP_MAIN_QUESTS_1_4][SS_TITLE] = "Willow",
    [SP_MAIN_QUESTS_1_4][SS_SP] = "I hit an engine on my head !",
    [SP_MAIN_QUESTS_1_5][SS_TITLE] = "Willow",
    [SP_MAIN_QUESTS_1_5][SS_SP] = "Help me find something to heal myself.",
    [SP_MAIN_QUESTS_1_6][SS_TITLE] = "(Me)",
    [SP_MAIN_QUESTS_1_6][SS_SP] = "Yes, stay here.",
    [SP_MAIN_QUESTS_2_1][SS_TITLE] = "(Me)",
    [SP_MAIN_QUESTS_2_1][SS_SP] = "I just found ruins.",
    [SP_MAIN_QUESTS_2_2][SS_TITLE] = "Willow",
    [SP_MAIN_QUESTS_2_2][SS_SP] = "Try to kill mobs. Maybe they can give \
something.",
    [SP_MAIN_QUESTS_2_3][SS_TITLE] = "(Me)",
    [SP_MAIN_QUESTS_2_3][SS_SP] = "If I can find a way to save myself.",
    [SP_QUEST_BACK_TALK_NPC_1][SS_TITLE] = "(Me)",
    [SP_QUEST_BACK_TALK_NPC_1][SS_SP] = "I've explored the surroundings quite \
a bit.\nI should go back and check on Willow.",
    [SP_SAVE_QUESTS_1][SS_TITLE] = "Volund",
    [SP_SAVE_QUESTS_1][SS_SP] = "I am Volund, the blacksmith of his island.\n\
I'm here to save the game.",
    [SP_SAVE_QUESTS_2][SS_TITLE] = "Willow",
    [SP_SAVE_QUESTS_2][SS_SP] = "Volund, hmm.\n \
It can be used for us for the whole game !",
    [SP_QUEST_BACK_TALK_NPC_2][SS_TITLE] = "(Me)",
    [SP_QUEST_BACK_TALK_NPC_2][SS_SP] = "I should return to see Willow.",
    [SP_SAVE][SS_TITLE] = "Volund",
    [SP_SAVE][SS_SP] = "I save your progress! Continue\n \
without pressure your story",
    [SP_FINAL_QUESTS_1_1][SS_TITLE] = "(Me)",
    [SP_FINAL_QUESTS_1_1][SS_SP] = "I finally found the chalice.",
    [SP_FINAL_QUESTS_1_2][SS_TITLE] = "(Me)",
    [SP_FINAL_QUESTS_1_2][SS_SP] = "It will surely help Willow.",
    [SP_MAIN_QUESTS_3_1][SS_TITLE] = "Willow",
    [SP_MAIN_QUESTS_3_1][SS_SP] = "Killing mobs is not enough, try to get xp",
    [SP_MAIN_QUESTS_3_2][SS_TITLE] = "NULL [2]",
    [SP_MAIN_QUESTS_3_2][SS_SP] = "The mobs can surely graduate you in the \
\nnorth towards new horizon",
    [SP_MAIN_QUESTS_END_1][SS_TITLE] = "Willow",
    [SP_MAIN_QUESTS_END_1][SS_SP] = "You give me.. ahh..",
    [SP_MAIN_QUESTS_END_2][SS_TITLE] = "Willow",
    [SP_MAIN_QUESTS_END_2][SS_SP] = "A poison..",
    [SP_MAIN_QUESTS_END_3][SS_TITLE] = "(Me)",
    [SP_MAIN_QUESTS_END_3][SS_SP] = "I killed my friends !?",
    [SP_MAIN_QUESTS_END_4][SS_TITLE] = "(Me)",
    [SP_MAIN_QUESTS_END_4][SS_SP] = "I will forever be all alone.."
};

static int speech_loaders_timer[SP_LEN] = {
    [SP_MAIN_QUESTS_1_1] = 6,
    [SP_MAIN_QUESTS_1_2] = 8,
    [SP_MAIN_QUESTS_1_3] = 6,
    [SP_MAIN_QUESTS_1_4] = 5,
    [SP_MAIN_QUESTS_1_5] = 5,
    [SP_MAIN_QUESTS_1_6] = 5,
    [SP_SAVE_QUESTS_1] = 6,
    [SP_SAVE_QUESTS_2] = 6,
    [SP_SAVE] = 6,
    [SP_QUEST_BACK_TALK_NPC_1] = 6,
    [SP_QUEST_BACK_TALK_NPC_2] = 5,
    [SP_MAIN_QUESTS_2_1] = 6,
    [SP_MAIN_QUESTS_2_2] = 6,
    [SP_MAIN_QUESTS_2_3] = 6,
    [SP_FINAL_QUESTS_1_1] = 6,
    [SP_FINAL_QUESTS_1_2] = 6,
    [SP_MAIN_QUESTS_3_1] = 6,
    [SP_MAIN_QUESTS_3_2] = 6,
    [SP_MAIN_QUESTS_END_1] = 6,
    [SP_MAIN_QUESTS_END_2] = 6,
    [SP_MAIN_QUESTS_END_3] = 6,
    [SP_MAIN_QUESTS_END_4] = 6
};

#endif /* !RESSOURCES_SPEECH_LOADERS_H */
