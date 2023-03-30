/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_

    #include "components/components.h"

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


#endif /* !COMPONENTS_H_ */
