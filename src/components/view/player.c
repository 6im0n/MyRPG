/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** player
*/

#include <math.h>
#include "types/type.h"

static sfVector2f normal_pos(sfVector2f posm, sfVector2f posp, float speed)
{
    sfVector2f dir = {posp.x - posm.x, posp.y - posm.y};
    float length = sqrt(pow(dir.x, 2) + pow(dir.y, 2));
    sfVector2f normalized_dir = {dir.x / length, dir.y / length};
    sfVector2f normalized_pos = {posm.x + normalized_dir.x * speed,
        posm.y + normalized_dir.y * speed};

    return normalized_pos;
}

static void player_transition(app_t *app, sfVector2f position)
{
    sfVector2f center = sfView_getCenter(app->element->player->view);
    sfVector2f new_pos = normal_pos(center, position, 3);

    sfView_setCenter(app->element->player->view, new_pos);
    if (new_pos.x <= center.x)
        app->state->transition = false;
}

void all_transition(app_t *app)
{
    sfRectangleShape *shape = app->state->cycle->shape;
    sfTime t = sfClock_getElapsedTime(app->state->cycle->clock);
    sfColor c = sfRectangleShape_getFillColor(shape);
    int t_set = 2;
    int c_max = 255;

    if (c.a <= 0) {
        sfRenderWindow_drawRectangleShape(app->window, shape, NULL);
        return;
    }
    c.a = (c_max - ((sfTime_asSeconds(t) - t_set) / (t_set)) * c_max) - 1;
    sfRectangleShape_setFillColor(shape, c);
    sfRenderWindow_drawRectangleShape(app->window, shape, NULL);
}

void player_view(app_t *app)
{
    sfVector2f position = {0, 0};
    sfRectangleShape *rect = app->element->player->character->shape;

    if ((app->state->stage == S_DEATH || app->state->stage == S_SETTINGS ||
        app->state->stage == S_INVENTORY || app->element->pop_up->first) &&
        app->state->back == S_GAME)
        sfRenderWindow_setView(app->window, app->element->player->view);
    if (app->state->stage == S_GAME){
        position = sfRectangleShape_getPosition(rect);
        if (app->state->transition)
            player_transition(app, position);
        else
            sfView_setCenter(app->element->player->view, position);
        sfRenderWindow_setView(app->window, app->element->player->view);
    }
}
