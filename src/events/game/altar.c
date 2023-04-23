/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** altar
*/

#include "types/type.h"
#include "components/components.h"
#include "event/global.h"
#include "types/list.h"
#include "app/app.h"
#include <stdlib.h>
#include <stdio.h>
#include "event/levels.h"

static void quest_gestion(node_component_t *component,
app_t *app)
{
    bool active = false;

    if (component->features.select == false)
        active = quests_current_add(app->element->quests, Q_FINAL);
    if (active) {
        component->features.select = true;
        new_popup(app, P_ADVENCED, 5);
        quests_get_finish(app, app->element->quests,
        Q_FINAL, SP_FINAL_QUESTS_1_1);
        add_item_player(app, I_CHALICE);
        component->annimation.max = 38;
        component->features.select = true;
        component->annimation.speed = 0.1;
        component->annimation.index = 0;
        component->annimation.one = true;
        component->annimation.clock = sfClock_create();
    }
}

void altar_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    if (!ST_IS_NEAR(component) || component->features.select)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        if (app->element->player->exprerience.level >= 20) {
            quest_gestion(component, app);
        } else {
            new_popup(app, P_NO_ENOUGHT_XP, 5);
        }
    }
}

void altar_events_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    if (component->annimation.one == true)
        return;
    component->annimation.max = 8;
}
