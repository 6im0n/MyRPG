/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "components/components.h"
#include <stdio.h>
#include "lib/str.h"
#include "event/global.h"
#include "components/player.h"

void event_item_info_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    sfText *text = component->object->text;
    char *name = NULL;
    char *weight = NULL;
    char *sharpness = NULL;

    (void) app;
    (void) event;
    if (app->element->player->inventory->first) {
        name = app->element->player->inventory->first->name;
        weight = app->element->player->inventory->first->weight;
        sharpness = app->element->player->inventory->first->sharpness;
        if (component->id == ID_NAME_ITEM)
            sfText_setString(text, name);
        if (component->id == ID_WEIGHT_ITEM)
            sfText_setString(text, weight);
        if (component->id == ID_SHARPNESS_ITEM)
            sfText_setString(text, sharpness);
    }
}

void event_key_inventory_open_onkeypressed(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
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
    if (sfKeyboard_isKeyPressed(sfKeyI) ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
        app->state->stage = app->state->back;
}

void item_player_hover(node_component_t *component, event_t *event, app_t *app)
{
    (void) event;
    (void) app;
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
