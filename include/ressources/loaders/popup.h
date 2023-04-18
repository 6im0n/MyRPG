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
    [P_ADVENCED] = "You made a progress in a quest !"
};

#endif /* !RESSOURCES_POPUP_LOADERS_H_ */
