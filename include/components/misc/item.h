/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** item
*/

#ifndef INVENTORY_ITEM_H_
    #define INVENTORY_ITEM_H_

    #include "components/new.h"

/**
 * @brief Append swords
 * @param list list
 * @param ressources ressources
 */
void append_sword(list_item_t *list, ressources_t *ressources);

/**
 * @brief Append knif
 * @param list list
 * @param ressources ressources
 */
void append_knif(list_item_t *list, ressources_t *ressources);

/**
 * @brief Append hammers
 * @param list list
 * @param ressources ressources
 */
void append_hammer(list_item_t *list, ressources_t *ressources);

#endif /* !ITEM_H_ */
