/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** events
*/

#include <math.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "components/view.h"
#include "components/player.h"
#include "event/game/global.h"
#include "components/misc/events.h"
#include "event/levels.h"

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

static void component_event_dispach_extend(app_t *app,
event_t *event, main_components_t *components)
{
    switch (app->state->stage) {
        case S_MENU_LOAD_GAME:
            components_dispatch_event(components->load_game, event, app);
            break;
        case S_MENU_HELP:
            components_dispatch_event(components->help_menu, event, app);
            break;
        case S_NEW_GAME:
            components_dispatch_event(components->new_game, event, app);
            break;
        default:
            break;
    }
}

static void reset_move_player(app_t *app)
{
    app->element->player->character->key.left = false;
    app->element->player->character->key.right = false;
    app->element->player->character->key.up = false;
    app->element->player->character->key.down = false;
}

static void component_event_dispatch(app_t *app,
event_t *event, main_components_t *components)
{
    switch (app->state->stage) {
        case S_MENU_START:
            components_dispatch_event(components->start_menu, event, app);
            break;
        case S_INVENTORY:
            reset_move_player(app);
            components_dispatch_event(components->inventory, event, app);
            break;
        case S_SETTINGS:
            reset_move_player(app);
            components_dispatch_event(components->setting, event, app);
            break;
        case S_GAME:
            components_dispatch_event(components->game, event, app);
            break;
        default:
            break;
    }
    component_event_dispach_extend(app, event, components);
    components_dispatch_event(components->cursor, event, app);
}

void app_handle_events(app_t *app, main_components_t *components)
{
    event_t event;

    while (sfRenderWindow_pollEvent(app->window, &(event.original))) {
        if (event.original.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        event.mouse = &(app->mouse);
        event_handle_mouse(app, &event);
        component_event_dispatch(app, &event, components);
        manage_view(app, &event, components);
    }
    if (app->state->stage == S_GAME) {
        if (finish_attack_player(app))
            move_player(app);
        else
            update_move(app);
        player_attack(app);
        component_near(components->game, app, &event);
    }
    update_xp(app, components);
}
