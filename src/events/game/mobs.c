/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** mobs
*/

#include "components/components.h"
#include "types/type.h"

bool mobs_next_to_player(app_t *app, node_mob_t *mob)
{
    sfFloatRect rect;
    sfFloatRect rectp = sfRectangleShape_getGlobalBounds(
            app->element->player->character->shape);
    bool on_me = false;
    int radius = mob->radius;

    if (mob->radius == 0)
        return false;
    rect = sfRectangleShape_getGlobalBounds(mob->shape);
    rect.top -= radius;
    rect.left -= radius;
    rect.width += radius * 2;
    rect.height += radius * 2;
    on_me = sfFloatRect_intersects(&rect, &rectp, NULL);
    return on_me;
}

void mobs_near(list_components_t *component,
app_t *app, event_t *event)
{
    (void) event;
    node_component_t *tmp = component->first;
    node_component_t *tmp2 = tmp;

    if (!component)
        return;
    while (tmp != NULL) {
        tmp2 = tmp->next;
        if (tmp->features.radius > 0 && component_next_to_player(tmp, app)) {
            tmp->state = ST_SET_NEAR(tmp, true);
            component_next_to(tmp, event, app);
        } else {
            tmp->state = ST_SET_NEAR(tmp, false);
            component_ondisabled(tmp, event, app);
        }
        tmp = tmp2;
    }
}