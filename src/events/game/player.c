/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/types.h"
#include "components/components.h"
#include "event/global.h"

void move_player(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    sfVector2f position = sfRectangleShape_getPosition(component->object->rectangle);

    if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp)) 
        position.y -= 5;
    if (sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyDown)) 
        position.y += 5;
    if (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyLeft))
        position.x -= 5;
    if (sfKeyboard_isKeyPressed(sfKeyD) || sfKeyboard_isKeyPressed(sfKeyRight))
        position.x += 5;
    sfRectangleShape_setPosition(component->object->rectangle, position);
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(component->object->rectangle);
    component->features.rendered_rect = rect;
}

void event_game_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) component;
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
   move_player(component, event, app);
}
