/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** info
*/

#include "components/components.h"
#include "components/speech.h"

static bool currend_info(app_t *app, node_quests_t *node, speech_id_t id)
{
    if (node->current >= node->goal) {
        new_speech(app, id);
        return true;
    }
    return false;
}

bool quests_get_finish(app_t *app, list_quests_t *list,
quests_t id, speech_id_t speech)
{
    node_quests_t *tmp = list->first;
    node_quests_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->id == id)
            return currend_info(app, tmp, speech);
        tmp = tmp2;
    }
    return false;
}
