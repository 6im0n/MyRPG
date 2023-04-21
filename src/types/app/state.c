/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** state
*/

#include "types/type.h"
#include <stdlib.h>
#include "app/constants.h"

static void set_sound_app(state_t *state)
{
    sfSound *sounds_old = sfSound_create();
    sfSound *sounds_new = sfSound_create();

    state->sound = malloc(sizeof(sounds_t));
    if (!state->sound)
        state->sound = NULL;
    state->sound->music = sounds_new;
    state->sound->sound = sounds_old;
    state->sound->mute = true;
    state->sound->stage_level = 0;
    state->sound->volume_music = 50;
    state->sound->volume_sound = 50;
}

static dn_cycle_t *set_cycle(void)
{
    dn_cycle_t *cycle = malloc(sizeof(dn_cycle_t));
    sfVector2f size = {13024, 8000};
    sfColor color = {0, 0, 0, 100};

    if (!cycle)
        return NULL;
    cycle->clock = sfClock_create();
    cycle->shape = sfRectangleShape_create();
    cycle->cycle = DAY;
    sfRectangleShape_setSize(cycle->shape, size);
    sfRectangleShape_setFillColor(cycle->shape, color);
    return cycle;
}

state_t *state_new(void)
{
    state_t *state = malloc(sizeof(state_t));

    if (!state)
        return NULL;
    state->stage = S_MENU_START;
    state->back = S_MENU_START;
    set_sound_app(state);
    state->clock = sfClock_create();
    state->framerate = W_FRAMERATE;
    state->transition = false;
    state->cycle = set_cycle();
    return state;
}

void state_free(state_t *state)
{
    sfSound_destroy(state->sound->music);
    sfSound_destroy(state->sound->sound);
    sfClock_destroy(state->clock);
    sfClock_destroy(state->cycle->clock);
    sfRectangleShape_destroy(state->cycle->shape);
    free(state->cycle);
    free(state->sound);
    free(state);
}
