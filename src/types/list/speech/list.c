/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** list
*/

#include "components/components.h"
#include "components/speech.h"
#include <stdlib.h>

void auto_call(app_t *app, speech_id_t id)
{
    if (id >= SP_MAIN_QUESTS_1_1 && id < SP_MAIN_QUESTS_1_6)
        new_speech(app, id + 1);
    if (id >= SP_MAIN_QUESTS_2_1 && id < SP_MAIN_QUESTS_2_3)
        new_speech(app, id + 1);
}

void list_removes(list_speech_t *list, node_speech_t *node)
{
    if (!node)
        return;
    if (node->next == NULL) {
        list->first = NULL;
        list->last = NULL;
    } else {
        list->first = node->next;
        node->prev = NULL;
    }
    list->len--;
    sfText_destroy(node->paragraphe);
    sfText_destroy(node->title);
    sfRectangleShape_destroy(node->shape);
    free(node);
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
