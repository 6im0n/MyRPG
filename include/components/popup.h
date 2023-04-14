/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** popup
*/

#ifndef POPUP_H_
    #define POPUP_H_

    #include <SFML/Graphics.h>

typedef enum e_pop_up_type {
    P_NONE,
    P_QUESTS,
    P_XP,
    P_ITEM
} type_popup_t;

typedef struct s_node_popup {
    struct s_node_popup *next;
    type_popup_t type;
    sfClock *clock;
    sfRectangleShape *shape;
    int auto_destroy;
    struct s_node_popup *prev;
} node_popup_t;

typedef struct s_list_pop_up {
    node_popup_t *first;
    int len;
    node_popup_t *last;
} list_pop_up_t;

/**
 * @brief Init the list of popup
 * @return list_pop_up_t*
 */
list_pop_up_t *list_pop_up_init(void);

/**
 * @brief Free the list of popup
 * @param list list
 */
void list_pop_up_free(list_pop_up_t *list);

/**
 * @brief Append new nod for pop_up
 * @param list list
 * @param node node
 */
void list_pop_up_append(list_pop_up_t *list, node_popup_t *node);

#endif /* !POPUP_H_ */
