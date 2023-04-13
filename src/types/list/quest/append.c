/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** append
*/

#include "lib/tools.h"
#include "types/list.h"
#include "ressources/loaders/quests.h"

void quest_append(list_quests_t *list, quests_t quest)
{
    node_quests_t *q_main_1 = list_node_qest_append(quest);

    (void) quests_loaders[0][0];
    list_quest_append(list, q_main_1);
}

node_quests_t *list_node_qest_append(quests_t quests)
{
    node_quests_t *node = malloc(sizeof(node_quests_t));
    node_quests_text_t *text = malloc(sizeof(node_quests_text_t));

    if (!node || !text)
        return NULL;
    node->next = NULL;
    node->prev = NULL;
    node->current = 0;
    node->finish = false;
    node->goal = 0;
    text->title = quests_loaders[quests][TQ_TITLE];
    text->description = quests_loaders[quests][TQ_DESCRIPTION];
    text->detail = quests_loaders[quests][TQ_DETAIL];
    text->objectif = quests_loaders[quests][TQ_OBJECTIF];
    text->reward = quests_loaders[quests][TQ_REWARD];
    node->text = text;
    return node;
}

void list_quest_append(list_quests_t *list, node_quests_t *node)
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
