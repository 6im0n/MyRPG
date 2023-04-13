/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#include "components/components.h"

list_quests_t *list_quests_init(void)
{
    list_quests_t *tmp = malloc(sizeof(list_quests_t));

    if (!tmp)
        return NULL;
    tmp->first = NULL;
    tmp->last = NULL;
    tmp->len = 0;
    return tmp;
}

void list_quests_free(list_quests_t *list)
{
    node_quests_t *tmp = list->first;
    node_quests_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        sfRectangleShape_destroy(tmp->shape);
        sfText_destroy(tmp->txt);
        free(tmp->text);
        free(tmp);
        tmp = tmp2;
    }
    free(list);
}
