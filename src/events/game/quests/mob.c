/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mob
*/

#include "types/type.h"
#include "components/components.h"
#include "event/global.h"
#include "components/new.h"
#include "event/start_menu/bouton.h"
#include "components/player.h"
#include "types/list.h"
#include "app/app.h"
#include "components/speech.h"

void mob_dying_quests(app_t *app)
{
    bool active = false;

    active = quests_current_add(app->element->quests, Q_MAIN_P2);
    if (active) {
        new_popup(app, P_ADVENCED, 5);
        quests_get_finish(app, app->element->quests,
        Q_MAIN_P2, SP_SAVE_QUESTS_1);
    }
}