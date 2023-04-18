/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** player
*/

#include "types/type.h"

void player_view(app_t *app)
{
    sfVector2f position = {0, 0};
    sfRectangleShape *rect = app->element->player->character->shape;

    if ((app->state->stage == S_SETTINGS || app->state->stage == S_INVENTORY ||
        app->element->pop_up->first) && app->state->back == S_GAME)
        sfRenderWindow_setView(app->window, app->element->player->view);
    if (app->state->stage == S_GAME){
        position = sfRectangleShape_getPosition(rect);
        sfView_setCenter(app->element->player->view, position);
        sfRenderWindow_setView(app->window, app->element->player->view);
    }
}
