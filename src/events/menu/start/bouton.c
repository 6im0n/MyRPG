/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/types.h"
#include "components/components.h"

void event_bouton_play_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;

    app->state->back = app->state->stage;
    app->state->stage = S_MENU_HELP;
}

void event_menu_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        app->state->back = app->state->stage;
        app->state->stage = S_INVENTORY;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        app->state->back = app->state->stage;
        app->state->stage = S_SETTINGS;
    }
}
