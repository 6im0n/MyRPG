/*
** EPITECH PROJECT, 2023
** FT-MyPaint
** File description:
** state
*/

#include "types/type.h"
#include "app/constants.h"
#include <stdlib.h>

state_t *state_new(void)
{
    state_t *state = malloc(sizeof(state_t));
    sfSound *sounds = sfSound_create();
    sounds_t sound = { sounds, sounds, 0, 50, false};

    if (!state)
        return NULL;
    state->stage = S_START_MENU;
    state->sound = &sound;
    state->transition = false;
    return state;
}

void state_free(state_t *state)
{
    sfSound_destroy(state->sound->old);
    sfSound_destroy(state->sound->new);
    free(state);
}
