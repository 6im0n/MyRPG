/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/types.h"
#include "components/components.h"
#include <stdio.h>

void event_key_inventory_open_onkeypressed(node_component_t *component,
event_t *event, app_t *app)
{
    (void) app;
    (void) component;
    (void) event;
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        app->state->back = app->state->stage;
        app->state->stage = S_INVENTORY;
    }
}

void event_key_inventory_close_onkeypressed(node_component_t *component,
event_t *event, app_t *app)
{
    (void) app;
    (void) component;
    (void) event;
    if (sfKeyboard_isKeyPressed(sfKeyE))
        app->state->stage = app->state->back;
}
