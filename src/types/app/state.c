/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** state
*/

#include "types/type.h"
#include <stdlib.h>

state_t *state_new(void)
{
    state_t *state = malloc(sizeof(state_t));
    sfSound *sounds_old = sfSound_create();
    sfSound *sounds_new = sfSound_create();

    if (!state)
        return NULL;
    return state;
}

void state_free(state_t *state)
{
    sfSound_destroy(state->sound->old);
    sfSound_destroy(state->sound->new);
    free(state->sound);
    free(state);
}
