/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include <stdio.h>
#include "components/components.h"
#include "lib/output.h"

static void event_bouton_help_move_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    component->features.texture_rect.left = 107;
}

static void event_bouton_help_move_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void)component;
    component->features.texture_rect.left = 11;
}

static void event_key_switch(node_component_t *component,
event_t *event, app_t *app)
{
    node_component_t *keyQ = component->next;
    node_component_t *keyS = component->next->next;
    node_component_t *keyD = component->next->next->next;

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        event_bouton_help_move_onkeypress(component, event, app);
    else
        event_bouton_help_move_ondisabled(component, event, app);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        event_bouton_help_move_onkeypress(keyQ, event, app);
    else
        event_bouton_help_move_ondisabled(keyQ, event, app);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        event_bouton_help_move_onkeypress(keyS, event, app);
    else
        event_bouton_help_move_ondisabled(keyS, event, app);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        event_bouton_help_move_onkeypress(keyD, event, app);
    else
        event_bouton_help_move_ondisabled(keyD, event, app);
}

void event_menu_help_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;

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
    event_key_switch(component->next->next->next, event, app);
}

void event_menu_help_onkeyrelease(node_component_t *component,
event_t *event, app_t *app)
{
    node_component_t *keyZ = component->next->next->next;
    node_component_t *keyQ = keyZ->next;
    node_component_t *keyS = keyQ->next;

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        event_bouton_help_move_onkeypress(keyZ, event, app);
    else
        event_bouton_help_move_ondisabled(keyZ, event, app);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        event_bouton_help_move_onkeypress(keyQ, event, app);
    else
        event_bouton_help_move_ondisabled(keyQ, event, app);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        event_bouton_help_move_onkeypress(keyS, event, app);
    else
        event_bouton_help_move_ondisabled(keyS, event, app);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        event_bouton_help_move_onkeypress(keyS->next, event, app);
    else
        event_bouton_help_move_ondisabled(keyS->next, event, app);
}
