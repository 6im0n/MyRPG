/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/type.h"
#include "components/components.h"
#include "event/global.h"
#include "components/new.h"

void idle_player(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;
}

void event_game_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) component;
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        if (app->state->stage != S_INVENTORY &&
            app->state->stage != S_MENU_HELP &&
            app->state->stage != S_SETTINGS)
            app->state->back = app->state->stage;
        app->state->stage = S_INVENTORY;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (app->state->stage != S_INVENTORY &&
            app->state->stage != S_MENU_HELP &&
            app->state->stage != S_SETTINGS)
            app->state->back = app->state->stage;
        app->state->stage = S_SETTINGS;
    }
}
