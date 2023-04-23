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
event_t *event, app_t *app, int id)
{
    (void) event;
    (void) component;
    if (id == 1)
        app->element->player->character->key.up = true;
    if (id == 2)
        app->element->player->character->key.left = true;
    if (id == 3)
        app->element->player->character->key.down = true;
    if (id == 4)
        app->element->player->character->key.right = true;
}

static void event_bouton_help_move_ondisabled(node_component_t *component,
event_t *event, app_t *app, int id)
{
    (void) event;
    (void) app;
    (void) component;
    if (id == 1)
        app->element->player->character->key.up = false;
    if (id == 2)
        app->element->player->character->key.left = false;
    if (id == 3)
        app->element->player->character->key.down = false;
    if (id == 4)
        app->element->player->character->key.right = false;
}

static void event_key_switch(node_component_t *component,
event_t *event, app_t *app)
{
    node_component_t *keyQ = component->next;
    node_component_t *keyS = component->next->next;
    node_component_t *keyD = component->next->next->next;

    if (sfKeyboard_isKeyPressed(sfKeyZ))
        event_bouton_help_move_onkeypress(component, event, app, 1);
    else
        event_bouton_help_move_ondisabled(component, event, app, 1);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        event_bouton_help_move_onkeypress(keyQ, event, app, 2);
    else
        event_bouton_help_move_ondisabled(keyQ, event, app, 2);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        event_bouton_help_move_onkeypress(keyS, event, app, 3);
    else
        event_bouton_help_move_ondisabled(keyS, event, app, 3);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        event_bouton_help_move_onkeypress(keyD, event, app, 4);
    else
        event_bouton_help_move_ondisabled(keyD, event, app, 4);
}

void event_menu_help_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
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
    if (!component->next || !component->next->next ||
    !component->next->next->next || !component->next->next->next)
        return;
    event_key_switch(component->next->next->next, event, app);
}

void event_menu_help_onkeyrelease(node_component_t *component,
event_t *event, app_t *app)
{
    if (!component->next || !component->next->next ||
    !component->next->next->next || !component->next->next->next)
        return;
    event_key_switch(component->next->next->next, event, app);
}
