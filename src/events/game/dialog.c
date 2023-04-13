/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** dialog
*/

#include <stdio.h>
#include "types/type.h"
#include "components/components.h"
#include "event/global.h"
#include "components/new.h"
#include "event/start_menu/bouton.h"
#include "components/player.h"

void dialog_main_quests_next_to(node_component_t *component,
event_t *event, app_t *app)
{
    sfVector2f scale =
        sfRectangleShape_getScale(component->prev->object->rectangle);

    (void) app;
    (void) event;
    (void) component;
    if (scale.x > 0) {
        scale.x -= 0.05;
        scale.y -= 0.05;
    }
    sfRectangleShape_setScale(component->prev->object->rectangle, scale);
}

void dialog_main_quests_disabled(node_component_t *component,
event_t *event, app_t *app)
{
    sfVector2f scale =
        sfRectangleShape_getScale(component->prev->object->rectangle);

    (void) app;
    (void) event;
    (void) component;
    if (scale.x < 1) {
        scale.x += 0.05;
        scale.y += 0.05;
    }
    sfRectangleShape_setScale(component->prev->object->rectangle, scale);
}

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

void dialog_main_quests_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;
    if (!ST_IS_NEAR(component))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyR)) {
        app->element->quests->first->current++;
        if (app->element->quests->first->current >=
            app->element->quests->first->goal)
            app->element->quests->first->finish = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        if (app->element->quests->len == 0)
            quest_append(app->element->quests, Q_MAIN_P1);
        if (app->element->quests->len == 1 &&
            find_result_quests(app->element->quests, Q_MAIN_P1) == true) {
            add_item_player(app, I_SWORD_LEV3);
            quest_append(app->element->quests, Q_MAIN_P2);
            }
    }
}
