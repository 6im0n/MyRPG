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
#include "event/global.h"
#include "lib/output.h"
#include "components/player.h"

void event_key_inventory_open_onkeypressed(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        if (app->state->stage != S_INVENTORY &&
            app->state->stage != S_MENU_HELP &&
            app->state->stage != S_SETTINGS)
            app->state->back = app->state->stage;
        app->state->stage = S_MENU_HELP;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (app->state->stage != S_MENU_HELP &&
            app->state->stage != S_SETTINGS)
            app->state->back = app->state->stage;
        app->state->stage = S_SETTINGS;
    }
}

void event_key_inventory_close_onkeypressed(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    if (sfKeyboard_isKeyPressed(sfKeyE) ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
        app->state->stage = app->state->back;
}

static void inventory_drop_done(node_component_t *component,
app_t *app)
{
    component_id_t last = app->element->player->inventory->last_select;
    component_id_t select = app->element->player->inventory->select;

    if (select != ID_UNDEFINED)
        last = component->id;
    component->state = ST_SET_CLICKED(component, false);
    component->state = ST_SET_PRESSED(component, false);
    if (last != ID_UNDEFINED && select != ID_UNDEFINED && last != select)
        swap_item_player(app->element->player->inventory, last, select);
}

void item_player_hover(node_component_t *component, event_t *event, app_t *app)
{
    (void) event;
    if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        app->element->player->inventory->select = ID_UNDEFINED;
        app->element->player->inventory->last_select = ID_UNDEFINED;
        return;
    }
    if (app->element->player->inventory->select == ID_UNDEFINED)
        app->element->player->inventory->select = component->id;
    else
        app->element->player->inventory->last_select = component->id;
}

void event_selector_onpress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    char *string = malloc(7);

    inventory_drop_done(component, app);
    my_strcpy(string, "Slot  ");
    string[5] = component->id + '0';
    event_play_music(component, app);
    free(string);
}
