/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/type.h"
#include "components/components.h"
#include "event/global.h"
#include "components/new.h"

void move_player(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) component;

    sfVector2f position = sfRectangleShape_getPosition(app->element->player->character->shape);

    if (sfKeyboard_isKeyPressed(sfKeyZ)){
        position.y -= 5;   
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)){
        position.y += 5;
        app->element->player->character->irect.top = 164;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        position.x -= 5;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        position.x += 5;

    sfRectangleShape_setPosition(app->element->player->character->shape, position);
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(app->element->player->character->shape);
    app->element->player->character->frect = rect;

}

void idle_player(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;
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
