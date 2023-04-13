/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** event_game
*/

#include <math.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "components/view.h"
#include "components/player.h"
#include "event/game/global.h"
#include "components/misc/events.h"

bool component_next_to_player(node_component_t *component,
app_t *app)
{
    sfFloatRect rect;
    sfVector2f pos =
        sfRectangleShape_getPosition(app->element->player->character->shape);
    bool on_me = false;
    int radius = component->features.radius;

    if (component->features.radius == 0)
        return false;
    rect = sfRectangleShape_getGlobalBounds(component->object->rectangle);
    rect.top -= radius;
    rect.left -= radius;
    rect.width += radius * 3;
    rect.height += radius * 3;
    on_me = sfFloatRect_contains(&rect, pos.x, pos.y);
    return on_me;
}

void component_near(list_components_t *component,
app_t *app, event_t *event)
{
    node_component_t *tmp = component->first;
    node_component_t *tmp2 = tmp;
    (void) event;
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

void move_player(app_t *app)
{
    sfRectangleShape *player_rect = app->element->player->character->shape;
    sfVector2f position = sfRectangleShape_getPosition(player_rect);
    sfFloatRect tmp_rect = {0, 0, 0, 0};
    bool array[4] = {false, false, false, false};
    float move = 1.5;

    collisions(array, position, app->element->player);
    if (app->element->player->character->key.up && array[0])
        position.y -= move;
    if (app->element->player->character->key.down && array[1])
        position.y += move;
    if (app->element->player->character->key.right && array[2])
        position.x += move;
    if (app->element->player->character->key.left && array[3])
        position.x -= move;
    sfRectangleShape_setPosition(player_rect, position);
    tmp_rect = sfRectangleShape_getGlobalBounds(player_rect);
    app->element->player->character->frect = tmp_rect;
}
