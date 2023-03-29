/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mouse
*/

#include "types/type.h"
#include "app/constants.h"

mouse_t mouse_init(void)
{
    mouse_t mouse = {
        false,
        DFT_MOUSE_POSITION,
        DFT_MOUSE_POSITION,
        DFT_MOUSE_POSITION,
        DFT_MOUSE_POSITION,
    };

    return mouse;
}
