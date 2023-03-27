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

    if (!state)
        return NULL;
    state->stage = S_START_MENU;
    state->transition = false;
    return state;
}

void state_free(state_t *state)
{
    free(state);
}
