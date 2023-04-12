/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#include <stdlib.h>
#include "types/type.h"
#include "components/mobs.h"

list_mobs_t *list_mobs_init(void)
{
    list_mobs_t *tmp = malloc(sizeof(list_mobs_t));

    if (!tmp)
        return NULL;
    tmp->first = NULL;
    tmp->last = NULL;
    tmp->len = 0;
    return tmp;
}

void list_mobs_free(list_mobs_t *list)
{
    node_mobs_t *tmp = list->first;
    node_mobs_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2;
    }
    free(list);
}
