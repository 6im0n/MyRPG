/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** levels
*/


#ifndef UPDATE_LEVELS_H_
    #define UPDATE_LEVELS_H_

    #include "components/components.h"

/**
 * @brief Update levels from player XP
 * @param app struct
 * @param list inventory component
 * @param xp xp to add
 */
void levels_update(app_t *app, list_components_t *list, int xp);


#endif /* !UPDATE_LEVELS_H_ */
