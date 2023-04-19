/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** main
*/

#include "types/type.h"
#include "components/components.h"
#include "event/global.h"
#include "components/new.h"
#include "event/start_menu/bouton.h"
#include "components/player.h"
#include "types/list.h"
#include "app/app.h"

void dialog_main_quests_onnext_to(node_component_t *component,
event_t *event, app_t *app)
{
    bool active = false;

    (void) event;
    if (!ST_IS_NEAR(component))
        return;
    if (component->features.select == false)
        active = quests_current_add(app->element->quests, Q_MAIN_P1);
    if (active) {
        component->features.select = true;
        new_popup(app, P_ADVENCED, 5);
    }
}
