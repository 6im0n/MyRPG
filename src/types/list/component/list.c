/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#include "components/components.h"

list_components_t *list_components_init(void)
{
    list_components_t *tmp = malloc(sizeof(list_components_t));

    if (!tmp)
        return NULL;
    tmp->first = NULL;
    tmp->last = NULL;
    tmp->len = 0;
    tmp->id = S_LEN;
    return tmp;
}

void list_components_free(list_components_t *list)
{
    node_component_t *tmp = list->first;
    node_component_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        free(tmp->object);
        free(tmp);
        tmp = tmp2;
    }
    free(list);
}
