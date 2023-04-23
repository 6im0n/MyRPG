/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** popup
*/

#ifndef RESSOURCES_POPUP_LOADERS_H_
    #define RESSOURCES_POPUP_LOADERS_H_

    #include "components/popup.h"
    #include "types/type.h"

static const char *popup_loaders[P_LEN] = {
    [P_ITEM] = "You have obtained an item !",
    [P_XP] = "You have gained experience points !",
    [P_QUESTS] = "A new quest has become available !",
    [P_ADVENCED] = "You made a progress in a quest !",
    [P_HEALT] = "You have regained some health points !",
    [P_WIN_SPEED] = "You have gained speed points !",
    [P_WIN_STRENGHT] = "You have gained strenght points !",
    [P_WIN_RESISTANCE] = "You have gained resistance points !",
    [P_WIN_LEVEL] = "You have gained level points !",
    [P_WIN_SKILL] = "You have gained skill points !",
    [P_SAVE] = "You save your party !"
};

#endif /* !RESSOURCES_POPUP_LOADERS_H_ */
