/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#include "components/components.h"

static void currend_add(node_quests_t *node)
{
    node->current++;
    if (node->current >= node->goal)
        node->finish = true;
}

bool quests_current_add(list_quests_t *list, quests_t id)
{
    node_quests_t *tmp = list->first;
    node_quests_t *tmp2 = tmp;
    bool find = false;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->id == id) {
            currend_add(tmp);
            find = true;
        }
        tmp = tmp2;
    }
    return find;
}

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
