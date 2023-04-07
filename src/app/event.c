/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** events
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "components/view.h"
#include <math.h>

static void event_handle_mouse(app_t *app, event_t *event)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(app->window);
    sfVector2f real = sfRenderWindow_mapPixelToCoords(app->window, pos, NULL);
    sfVector2f last_move = event->mouse->last_move_position;

    event->mouse->position = real;
    if (!app->mouse.pressed
        && event->original.type == sfEvtMouseButtonPressed
        && event->original.mouseButton.button == sfMouseLeft) {
        event->mouse->press_position = real;
        event->mouse->pressed = true;
    }
    if (event->original.type == sfEvtMouseMoved) {
        event->mouse->move_diff.x = real.x - last_move.x;
        event->mouse->move_diff.y = real.y - last_move.y;
        event->mouse->last_move_position = real;
    }
    if (event->original.type == sfEvtMouseButtonReleased)
        event->mouse->pressed = false;
}

static void component_event_dispatch(app_t *app,
event_t *event, main_components_t *components)
{
    switch (app->state->stage) {
        case S_MENU_START:
            components_dispatch_event(components->start_menu, event, app);
            break;
        case S_MENU_HELP:
            components_dispatch_event(components->help_menu, event, app);
            break;
        case S_INVENTORY:
            components_dispatch_event(components->inventory, event, app);
            break;
        case S_SETTINGS:
            components_dispatch_event(components->setting, event, app);
            break;
        case S_MENU_LOAD_GAME:
            components_dispatch_event(components->load_game, event, app);
            break;
        case S_GAME:
            components_dispatch_event(components->game, event, app);
            break;
        default:
            break;
    }
    components_dispatch_event(components->cursor, event, app);
}

void move_player(app_t *app)
{
    sfVector2f position = sfRectangleShape_getPosition(app->element->player->character->shape);
    //float move = 5.0f;
    fflush(stdout);
    static int i = 0;
    printf("passage\n%d" , i);
    i++;
    
    // if (sfKeyboard_isKeyPressed(sfKeyZ))
    //     app->element->player->character->key->up = 1;
    // if (sfKeyboard_isKeyPressed(sfKeyQ))
    //     app->element->player->character->key->left = 1;
    // if (sfKeyboard_isKeyPressed(sfKeyS))
    //     app->element->player->character->key->down = 1;
    // if (sfKeyboard_isKeyPressed(sfKeyD))
    //     app->element->player->character->key->right = 1;


    sfRectangleShape_setPosition(app->element->player->character->shape, position);
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(app->element->player->character->shape);
    app->element->player->character->frect = rect;
}

void app_handle_events(app_t *app, main_components_t *components)
{
    event_t event;

    while (sfRenderWindow_pollEvent(app->window, &(event.original))) {
        if (event.original.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        event.mouse = &(app->mouse);
        if (app->state->stage == S_GAME){
            move_player(app);

        }
        event_handle_mouse(app, &event);
        component_event_dispatch(app, &event, components);
        manage_view(app, &event, components);
    }
}
