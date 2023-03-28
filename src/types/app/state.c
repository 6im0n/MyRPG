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

    if (!state)
        return NULL;
    return state;
}

void state_free(state_t *state)
{
    free(state);
}
