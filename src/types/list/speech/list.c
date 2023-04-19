/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#include "components/components.h"
#include <stdio.h>

void list_removes(list_speech_t *list, node_speech_t *node)
{
    if (node->next == NULL) {
        list->first = NULL;
        list->last = NULL;
    } else {
        list->first = node->next;
        node->prev = NULL;
    }
    list->len--;
}

list_speech_t *list_speech_init(void)
{
    list_speech_t *tmp = malloc(sizeof(list_speech_t));

    if (!tmp)
        return NULL;
    tmp->first = NULL;
    tmp->last = NULL;
    tmp->len = 0;
    return tmp;
}

void list_speech_free(list_speech_t *list)
{
    node_speech_t *tmp = list->first;
    node_speech_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        sfClock_destroy(tmp->clock);
        sfText_destroy(tmp->title);
        sfText_destroy(tmp->paragraphe);
        sfRectangleShape_destroy(tmp->shape);
        free(tmp);
        tmp = tmp2;
    }
    free(list);
}
