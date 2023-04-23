/*
** EPITECH PROJECT, 2023
** FT-MyPaint
** File description:
** ressources
*/

#ifndef RESSOURCES_SOUNDS_LOADERS_H_
    #define RESSOURCES_SOUNDS_LOADERS_H_

    #include "ressources/sounds.h"

static char *sounds_loaders[SD_LEN] = {
    [SD_NONE] = "assets/sounds/user/grab.ogg",
    [SD_GRAB] = "assets/sounds/user/grab.ogg",
    [SD_EXPLORATION] = "assets/sounds/move/exploration.ogg",
    [SD_HEART] = "assets/sounds/user/heart.ogg",
    [SD_MOB_ATTACK] = "assets/sounds/mob/attack.ogg"
};

#endif /* !RESSOURCES_SOUNDS_LOADERS_H_ */
