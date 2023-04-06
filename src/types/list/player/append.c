/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** append
*/

#include "components/player.h"

void list_item_append(list_item_t *list, node_item_t *node)
{
    if (list->last != NULL) {
        node->next = NULL;
        list->last->next = node;
        node->prev = list->last;
    } else {
        node->next = list->first;
        list->first = node;
        node->prev = NULL;
    }
    list->last = node;
    list->len++;
}

static void node_unlink(node_item_t *node)
{
    if (!node)
        return;
    if (node->next)
        node->next->prev = node->prev;
    if (node->prev)
        node->prev->next = node->next;
}

void list_remove(list_item_t *list, node_item_t *node)
{
    node_unlink(node);
    if (list->first == node)
        list->first = node->next;
    if (list->first)
        list->first->prev = NULL;
    if (list->last == node)
        list->last = node->prev;
    if (list->last)
        list->last->next = NULL;
    list->len--;
}
