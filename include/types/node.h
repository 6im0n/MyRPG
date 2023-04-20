/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#ifndef NODE_H_
    #define NODE_H_

    #include "components/components.h"
    #include "components/player.h"

/**
 * @brief Init component node
 * @return node_component_t* new empty node
 */
node_component_t *node_component_init(void);

/**
 * @brief Init layer node
 * @return node_layer_t* node layer
 */
node_layer_t *layer_node_init(void);

#endif /* !NODE_H_ */
