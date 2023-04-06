/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/types.h"
#include "components/components.h"
#include <stdio.h>
#include "lib/str.h"
#include "event/global.h"
#include "lib/output.h"
#include "components/player.h"

void event_key_inventory_open_onkeypressed(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        if (app->state->stage != S_INVENTORY &&
            app->state->stage != S_MENU_HELP &&
            app->state->stage != S_SETTINGS)
            app->state->back = app->state->stage;
        app->state->stage = S_MENU_HELP;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (app->state->stage != S_MENU_HELP &&
            app->state->stage != S_SETTINGS)
            app->state->back = app->state->stage;
        app->state->stage = S_SETTINGS;
    }
}

void event_key_inventory_close_onkeypressed(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    if (sfKeyboard_isKeyPressed(sfKeyE) ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
        app->state->stage = app->state->back;
}

void item_player_hover(node_component_t *component, event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        app->element->player->inventory->select = ID_UNDEFINED;
        app->element->player->inventory->last_select = ID_UNDEFINED;
        return;
    }
    if (app->element->player->inventory->select == ID_UNDEFINED)
        app->element->player->inventory->select = component->id;
    else
        app->element->player->inventory->last_select = component->id;
}
