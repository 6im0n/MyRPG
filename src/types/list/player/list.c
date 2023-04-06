/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#include <stdlib.h>
#include "components/player.h"

list_item_t *list_item_init(void)
{
    list_item_t *tmp = malloc(sizeof(list_item_t));

    if (!tmp)
        return NULL;
    tmp->first = NULL;
    tmp->last = NULL;
    tmp->len = 0;
    return tmp;
}

void list_item_free(list_item_t *list)
{
    node_item_t *tmp = list->first;
    node_item_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2;
    }
    free(list);
}
