/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** state
*/

#include <stdio.h>
#include "components/components.h"
#include "components/misc/events.h"

static void targeted_set_state(node_component_t *component,
event_t *event, app_t *app)
{
    bool right = event->original.mouseButton.button == sfMouseRight;
    bool left = event->original.mouseButton.button == sfMouseLeft;

    if (event->original.type == sfEvtMouseButtonReleased)
        component->state = ST_SET_CLICKED(component, left);
    if (event->original.type == sfEvtMouseButtonReleased)
        component->state = ST_SET_R_CLICKED(component, right);
    if (event->mouse->pressed)
        component->state = ST_SET_PRESSED(component, true);
    else
        component->state = ST_SET_PRESSED(component, false);
    if (event->original.type == sfEvtMouseMoved && ST_IS_PRESSED(component))
        component->state = ST_SET_MOVED(component, true);
    else
        component->state = ST_SET_MOVED(component, false);
    (void) app;
}

static void non_targeted_set_state(node_component_t *component)
{
    component->state = ST_SET_HOVER(component, false);
    component->state = ST_SET_CLICKED(component, false);
    component->state = ST_SET_R_CLICKED(component, false);
    component->state = ST_SET_PRESSED(component, false);
    component->state = ST_SET_MOVED(component, false);
    component->state = ST_SET_NEAR(component, false);
}

void component_set_state_from_event(node_component_t *component,
event_t *event, app_t *app)
{
    sfFloatRect *rect = &component->features.rendered_rect;
    sfVector2f press = event->mouse->press_position;
    sfVector2f pos = event->mouse->position;
    sfVector2f pos_p =
        sfRectangleShape_getPosition(app->element->player->character->shape);
    bool on_me = sfFloatRect_contains(rect, pos.x, pos.y);
    bool on_player = sfFloatRect_contains(rect, pos_p.x, pos_p.y);

    if (ST_IS_NEAR(component) || (sfFloatRect_contains(rect, press.x, press.y)
        && event->mouse->pressed) || (!event->mouse->pressed && on_me)) {
        targeted_set_state(component, event, app);
        if ((sfFloatRect_contains(rect, press.x, press.y)
            && event->mouse->pressed) || (!event->mouse->pressed && on_me) ||
            (on_player))
            component->state = ST_SET_HOVER(component, true);
    } else {
        non_targeted_set_state(component);
    }
}
