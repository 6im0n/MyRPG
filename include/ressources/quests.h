/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** quests
*/

#ifndef RESSOURCES_QUESTS_H
    #define RESSOURCES_QUESTS_H

typedef enum e_quests_text {
    TQ_TITLE,
    TQ_DESCRIPTION,
    TQ_DETAIL,
    TQ_OBJECTIF,
    TQ_REWARD,
    TQ_LEN
} text_quests_t;

typedef enum e_quests {
    Q_UNDEFINED,
    Q_MAIN_P1,
    Q_MAIN_P2,
    Q_MAIN_P3,
    Q_MAIN_P4,
    Q_SAVE,
    Q_FINAL,
    Q_LEN
} quests_t;

#endif /* !RESSOURCES_QUESTS_H */
