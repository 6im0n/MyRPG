/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** constants
*/

#ifndef APP_CONSTANTS_H_
    #define APP_CONSTANTS_H_

    #include <SFML/Graphics.h>

    #define W_VIDEO_MODE ((sfVideoMode) {1920, 1080, 32})
    #define W_TITLE "RPG - Island'or"
    #define W_FRAMERATE 165
    #define W_COLOR ((sfColor) {232, 207, 166, 255})

    #define DFT_MOUSE_POSITION ((sfVector2f) {0, 0})
    #define SAVE_FILE "assets/scripts/log/game.txt"

#endif /* !APP_CONSTANTS_H_ */
