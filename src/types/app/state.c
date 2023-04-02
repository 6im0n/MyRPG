/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** state
*/

#include "types/type.h"
#include <stdlib.h>
#include "app/constants.h"

state_t *state_new(void)
{
    state_t *state = malloc(sizeof(state_t));
    sfSound *sounds_old = sfSound_create();
    sfSound *sounds_new = sfSound_create();

    if (!state)
        return NULL;
    state->stage = S_MENU_START;
    state->back = S_MENU_START;
    state->sound = malloc(sizeof(sounds_t));
    state->sound->new = sounds_new;
    state->sound->old = sounds_old;
    state->sound->mute = true;
    state->clock = sfClock_create();
    state->sound->stage_level = 0;
    state->sound->volume = 50;
    state->framerate = W_FRAMERATE;
    state->transition = false;
    return state;
}

void state_free(state_t *state)
{
    sfSound_destroy(state->sound->old);
    sfSound_destroy(state->sound->new);
    sfClock_destroy(state->clock);
    free(state->sound);
    free(state);
}
