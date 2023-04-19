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
    SP_MAIN_QUESTS_1,
    SP_MAIN_QUESTS_2,
    SP_LEN
} speech_id_t;

typedef enum e_speech_states {
    STS_NONE,
    STS_APPARITION,
    STS_DEPOP
} speech_states_t;

#endif /* !RESSOURCES_SPEECH_H_ */
