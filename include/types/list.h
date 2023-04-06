/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_

    #include "components/components.h"
    #include "components/player.h"

/**
 * @brief Initialise a list of components
 * @return list_components_t* new list
 */
list_components_t *list_components_init(void);

/**
 * @brief Free a list of components
 * @param list list to free
 */
void list_components_free(list_components_t *list);

/**
 * @brief Append a Node to List
 * @param list list of component
 * @param node Component node
 */
void list_component_append(list_components_t *list, node_component_t *node);

/**
 * @brief Append a Item to List
 * @param list
 * @param node
 */
void list_item_append(list_item_t *list, node_item_t *node);

/**
 * @brief Initialise a list of components
 * @return list_item_t*
 */
list_item_t *list_item_init(void);

/**
 * @brief Free a list of items
 * @param list list to free
 */
void list_item_free(list_item_t *list);

#endif /* !COMPONENTS_H_ */
