/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/types.h"
#include "components/components.h"
#include "lib/output.h"

void event_bouton_help_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;
    app->state->stage = S_MENU_START;
}

void event_bouton_help_close_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;
    app->state->stage = app->state->back;
}

void event_bouton_help_open_inventory_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;
    if (app->state->stage != S_INVENTORY && app->state->stage != S_SETTINGS)
        app->state->back = app->state->stage;
    app->state->stage = S_INVENTORY;
}

void event_bouton_help_onhover(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;

    sfText_setColor(component->object->text, sfBlack);
}

void event_bouton_help_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;
    sfText_setColor(component->object->text, sfTransparent);
}
