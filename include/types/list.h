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
    #include "ressources/quests.h"

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

/**
 * @brief Init pure item
 * @return node_item_t*
 */
node_item_t *item_pure_new(void);;

/**
 * @brief Remvoe node to list
 * @param list list
 * @param node node
 */
void list_remove(list_item_t *list, node_item_t *node);

/**
 * @brief Append a quest to List
 * @param list
 * @param node
 */
void list_quest_append(list_quests_t *list, node_quests_t *node);

/**
 * @brief Return a quest node from the list
 * @param quests
 * @param list
 */
node_quests_t *list_node_qest_append(quests_t quests, list_quests_t *list);

/**
 * @brief Initialise a list of quests
 * @return list_quests_t*
 */
list_quests_t *list_quests_init(void);

/**
 * @brief Free a list of quests
 * @param list list to free
 */
void list_quests_free(list_quests_t *list);

/**
 * @brief delete a quest node to List
 * @param list
 * @param id
 */
void list_quest_delete(list_quests_t *list, quests_t id);

/**
 * @brief initialise a list of speech
 */
list_speech_t *list_speech_init(void);

/**
 * @brief free a list of speech
 * @param list
 */
void list_speech_free(list_speech_t *list);

/**
 * @brief initialise a list of layer
*/
list_layer_t *list_layers_init(void);

/**
 * @brief free a list of layer
 *
 * @param list
 */
void list_layers_free(list_layer_t *list);

/**
 * @brief append a node to a list of layer
 *
 * @param list
 * @param node
 */
void list_layer_append(list_layer_t *list, node_layer_t *node);

#endif /* !COMPONENTS_H_ */
