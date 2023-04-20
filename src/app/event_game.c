/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** event_game
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "components/view.h"
#include "components/player.h"
#include "event/game/global.h"
#include "components/misc/events.h"

bool component_next_to_player(node_component_t *component,
app_t *app)
{
    sfFloatRect rect = {0, 0, 0, 0};
    sfFloatRect rectp = sfRectangleShape_getGlobalBounds(
            app->element->player->character->shape);
    bool on_me = false;
    int radius = component->features.radius;

    if (component->features.radius == 0)
        return false;
    rect = sfRectangleShape_getGlobalBounds(component->object->rectangle);
    rect.top -= radius;
    rect.left -= radius;
    rect.width += radius * 2;
    rect.height += radius * 2;
    on_me = sfFloatRect_intersects(&rect, &rectp, NULL);
    return on_me;
}

void component_near(list_components_t *component,
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

static float update_move(app_t *app)
{
    float move = (float)app->element->player->skills.speed * 13.F;
    sfTime time = sfClock_getElapsedTime(app->state->clock);
    float seconds = time.microseconds / 1000000.0;
    sfTime old_time = app->element->player->character->time;
    float seconds_old = old_time.microseconds / 1000000.0;
    app->element->player->character->time = time;
    float spend = seconds - seconds_old;
    move *= spend;

    return move;
}

static sfVector2f move_player_diagonaly(float move,
sfVector2f position, app_t *app, bool *array)
{
    key_player_t key = app->element->player->character->key;

    if (key.up && key.right && array[0] && array[2] && !key.down) {
        position = change_animation_direction(app, position, move, 5);
    }
    if (key.down && array[1] && array[2] && key.right && !key.up) {
        position = change_animation_direction(app, position, move, 6);
    }
    if (key.up && array[0] && array[3] && key.left && !key.down ) {
        position = change_animation_direction(app, position, move, 7);
    }
    if (key.down && array[1] && array[3] && key.left && !key.up) {
        position = change_animation_direction(app, position, move, 8);
    }
    position = move_player_on_wall_vertical(move, position, app, array);
    position = move_player_on_wall_horizontal(move, position, app, array);
    return position;
}

void move_player(app_t *app)
{
    sfRectangleShape *player_rect = app->element->player->character->shape;
    sfVector2f position = sfRectangleShape_getPosition(player_rect);
    sfFloatRect tmp_rect = {0, 0, 0, 0};
    bool array[4] = {false, false, false, false};
    float move = update_move(app);
    key_player_t key_tmp = app->element->player->character->key;

    collisions(array, position, app->element->player);
    position = move_player_diagonaly(move, position, app, array);
    if (key_tmp.up && array[0] && !key_tmp.right && !key_tmp.left)
        position = change_animation_direction(app, position, move, 1);
    if (key_tmp.down && array[1] && !key_tmp.right && !key_tmp.left)
        position = change_animation_direction(app, position, move , 2);
    if (key_tmp.right && array[2] && !key_tmp.up && !key_tmp.down)
        position = change_animation_direction(app, position, move, 3);
    if (key_tmp.left && array[3] && !key_tmp.up && !key_tmp.down)
        position = change_animation_direction(app, position, move, 4);
    sfRectangleShape_setPosition(player_rect, position);
    tmp_rect = sfRectangleShape_getGlobalBounds(player_rect);
    app->element->player->character->frect = tmp_rect;
}
