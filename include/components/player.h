/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** components
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include <stdlib.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include "types/type.h"

/**
 * @brief Create a player
 * @return player_t*
 */
player_t *player_create(ressources_t *ressources);

/**
 * @brief Destroyed a player
 * @param player
 */
void player_destroy(player_t *player);

/**
 * @brief Add item to player
 * @param app
 * @param item
 */
void add_item_player(app_t *app, item_t item);
#endif /* !PLAYER_H_ */
