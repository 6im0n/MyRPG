/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** lunch
*/

#include "event/global.h"
#include "components/components.h"
#include "lib/output.h"

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
    sfVector2f pos = { 2420, 6375 };

    (void) component;
    (void) event;
    event_play_music(component, app);
    player->exprerience.level = 0;
    player->exprerience.xp = 0;
    sfRectangleShape_setPosition(player->character->shape, pos);
    app->state->back = app->state->stage;
    app->state->stage = S_GAME;
    sfClock_restart(app->state->cycle->clock);
    sfClock_restart(app->state->clock);
}
