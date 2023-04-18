/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include <stdio.h>
#include "types/type.h"
#include "components/components.h"
#include "event/global.h"
#include "components/new.h"
#include "event/start_menu/bouton.h"

static void event_bouton_help_move_onkeypress(app_t *app, int id)
{
    if (id == 1){
        app->element->player->character->key.up = true;
    }
    if (id == 2){
        app->element->player->character->key.left = true;
    }
    if (id == 3){
        app->element->player->character->key.down = true;
    }
    if (id == 4){
        app->element->player->character->key.right = true;
    }
}

static void event_bouton_help_move_ondisabledt(app_t *app, int id)
{
    if (id == 1){
        app->element->player->character->key.up = false;
        app->element->player->character->irect.top = 20;
    }
    if (id == 2)
        app->element->player->character->key.left = false;
    if (id == 3)
        app->element->player->character->key.down = false;
    if (id == 4)
        app->element->player->character->key.right = false;
}

void event_key_switch(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) component;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        event_bouton_help_move_onkeypress(app, 1);
    else
        event_bouton_help_move_ondisabledt(app, 1);
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        event_bouton_help_move_onkeypress(app, 2);
    else
        event_bouton_help_move_ondisabledt(app, 2);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        event_bouton_help_move_onkeypress(app, 3);
    else
        event_bouton_help_move_ondisabledt(app, 3);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        event_bouton_help_move_onkeypress(app, 4);
    else
        event_bouton_help_move_ondisabledt(app, 4);
}

void event_game_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
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
    event_key_switch(component, event, app);
}
