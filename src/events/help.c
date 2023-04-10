/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/


#include "components/components.h"
#include "event/global.h"

void event_open_help_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    event_play_music(component, app);
    if (app->state->stage != S_INVENTORY &&
        app->state->stage != S_MENU_HELP &&
        app->state->stage != S_SETTINGS)
        app->state->back = app->state->stage;
    app->state->stage = S_MENU_HELP;
}
