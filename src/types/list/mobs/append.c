/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** append
*/

#include "types/list.h"


void list_mobs_append(list_mobs_t *list, node_mob_t *node)
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
