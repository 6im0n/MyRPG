/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#include "types/types.h"
#include "components/components.h"

void event_bouton_play_onclick(node_component_t *component,
event_t *event, app_t *app)
{
    sfVector2f scale = {0.8, 0.8};

    (void) event;
    (void) app;
    sfRectangleShape_setScale(component->object->rectangle, scale);
    app->state->stage = S_GAME;
}
