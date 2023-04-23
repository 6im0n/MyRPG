/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** extend
*/

#include <stdio.h>
#include "types/type.h"
#include "components/components.h"
#include "event/global.h"
#include "components/new.h"
#include "event/start_menu/bouton.h"
#include "components/player.h"
#include "types/list.h"
#include "components/speech.h"

static bool find_result_quests(list_quests_t *list, quests_t quest)
{
    node_quests_t *tmp = list->first;
    node_quests_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->id == quest && tmp->finish == true)
            return true;
        tmp = tmp2;
    }
    return false;
}

void quests_extend_1(app_t *app)
{
    if (find_result_quests(app->element->quests, Q_SAVE) == true) {
        list_quest_delete(app->element->quests, Q_SAVE);
        new_speech(app, SP_SAVE_QUESTS_2);
        app->element->player->exprerience.update = 50;
    }
    if (find_result_quests(app->element->quests, Q_MAIN_P2) == true) {
        list_quest_delete(app->element->quests, Q_MAIN_P2);
        app->element->player->exprerience.update = 70;
        add_item_player(app, I_HAMMER_LEV4);
        quest_append(app, Q_MAIN_P3);
    }
}

void quests_extend_2(app_t *app)
{
    if (find_result_quests(app->element->quests, Q_MAIN_P3) == true) {
        list_quest_delete(app->element->quests, Q_MAIN_P3);
        new_speech(app, SP_MAIN_QUESTS_3_1);
        app->element->player->exprerience.update = 75;
        add_item_player(app, I_HAMMER_LEV4);
        quest_append(app, Q_MAIN_P4);
    }
    if (find_result_quests(app->element->quests, Q_MAIN_P4) == true) {
        list_quest_delete(app->element->quests, Q_MAIN_P4);
        new_speech(app, SP_MAIN_QUESTS_3_2);
        app->element->player->exprerience.update = 80;
        add_item_player(app, I_HAMMER_LEV4);
        quest_append(app, Q_FINAL);
    }
}

void quests_extend_3(app_t *app)
{
    if (find_result_quests(app->element->quests, Q_FINAL) == true) {
        list_quest_delete(app->element->quests, Q_MAIN_P4);
        new_speech(app, SP_MAIN_QUESTS_END_1);
        app->element->player->exprerience.update = 400;
    }
}
