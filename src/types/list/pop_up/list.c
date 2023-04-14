/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#include "components/components.h"

list_pop_up_t *list_pop_up_init(void)
{
    list_pop_up_t *tmp = malloc(sizeof(list_pop_up_t));

    if (!tmp)
        return NULL;
    tmp->first = NULL;
    tmp->last = NULL;
    tmp->len = 0;
    return tmp;
}

void list_pop_up_free(list_pop_up_t *list)
{
    node_popup_t *tmp = list->first;
    node_popup_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        sfClock_destroy(tmp->clock);
        sfText_destroy(tmp->text);
        sfRectangleShape_destroy(tmp->shape);
        free(tmp);
        tmp = tmp2;
    }
    free(list);
}
