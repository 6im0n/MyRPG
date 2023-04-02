/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/types.h"
#include "components/components.h"

void event_open_setting_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    if (app->state->stage != S_INVENTORY &&
        app->state->stage != S_MENU_HELP &&
        app->state->stage != S_SETTINGS)
        app->state->back = app->state->stage;
    app->state->stage = S_SETTINGS;
}
