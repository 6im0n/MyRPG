/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** speech
*/

#ifndef RESSOURCES_SPEECH_H_
    #define RESSOURCES_SPEECH_H_

typedef enum e_speech_style {
    SS_TITLE,
    SS_SP,
    SS_LEN
} speech_style_t;

typedef enum e_speech {
    SP_NONE,
    SP_MAIN_QUESTS_1_1,
    SP_MAIN_QUESTS_1_2,
    SP_MAIN_QUESTS_1_3,
    SP_MAIN_QUESTS_1_4,
    SP_MAIN_QUESTS_1_5,
    SP_MAIN_QUESTS_1_6,
    SP_SAVE_QUESTS_1,
    SP_SAVE_QUESTS_2,
    SP_SAVE,
    SP_QUEST_BACK_TALK_NPC_1,
    SP_QUEST_BACK_TALK_NPC_2,
    SP_MAIN_QUESTS_2_1,
    SP_MAIN_QUESTS_2_2,
    SP_MAIN_QUESTS_2_3,
    SP_FINAL_QUESTS_1_1,
    SP_FINAL_QUESTS_1_2,
    SP_MAIN_QUESTS_3_1,
    SP_MAIN_QUESTS_3_2,
    SP_MAIN_QUESTS_END_1,
    SP_MAIN_QUESTS_END_2,
    SP_MAIN_QUESTS_END_3,
    SP_MAIN_QUESTS_END_4,
    SP_LEN
} speech_id_t;

typedef enum e_speech_states {
    STS_NONE,
    STS_APPARITION,
    STS_DEPOP
} speech_states_t;

#endif /* !RESSOURCES_SPEECH_H_ */
