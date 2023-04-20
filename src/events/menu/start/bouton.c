/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "components/components.h"

void event_menu_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
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

void event_open_load_game_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    if (app->state->stage != S_INVENTORY &&
        app->state->stage != S_MENU_HELP &&
        app->state->stage != S_SETTINGS)
        app->state->back = app->state->stage;
    app->state->stage = S_MENU_LOAD_GAME;
}
