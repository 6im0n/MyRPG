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

void event_settings_open_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    app->state->back = app->state->stage;
    app->state->stage = S_SETTINGS;
}

void event_key_settings_close_onkeypressed(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        app->state->stage = app->state->back;
}
