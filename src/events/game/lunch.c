/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** lunch
*/

#include "event/global.h"
#include "components/components.h"
#include "lib/output.h"
#include "event/start_menu/bouton.h"

void launch_new_game(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    event_play_music(component, app);
    app->state->back = app->state->stage;
    app->state->stage = S_NEW_GAME;
}

void launch_game(node_component_t *component,
event_t *event, app_t *app)
{
    player_t *player = app->element->player;
    sfRectangleShape *shape = app->state->cycle->shape;
    sfVector2f pos = { 2420, 6375 };

    (void) component;
    (void) event;
    app->parsing = false;
    app->game = true;
    app->first = true;
    event_play_music(component, app);
    clear_old_game(app);
    sfRectangleShape_setPosition(player->character->shape, pos);
    app->state->back = app->state->stage;
    app->state->stage = S_GAME;
    app->state->transition = true;
    sfView_setCenter(app->element->player->view, (sfVector2f){1000, 6375});
    sfRectangleShape_setFillColor(shape, sfBlack);
    sfClock_restart(app->state->cycle->clock);
    sfClock_restart(app->state->clock);
}
