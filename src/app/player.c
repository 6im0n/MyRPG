/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#include "app/app.h"
#include "app/constants.h"
#include "app/ressources.h"
#include "components/mobs.h"
#include "components/player.h"
#include "components/components.h"

void app_quests_dispatch(app_t *app)
{
    node_quests_t *tmp = app->element->quests->first;
    node_quests_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        sfRenderWindow_drawRectangleShape(app->window, tmp->shape, NULL);
        quests_set_text_position(app, tmp);
        tmp = tmp2;
    }
}

void app_player_render(app_t *app)
{
    if (app->state->stage == S_GAME || app->state->stage == S_SETTINGS ||
        app->state->stage == S_INVENTORY) {
        player_render_annimation(app);
        if (!app->element->player->front)
            sfRenderWindow_drawRectangleShape(app->window,
            app->element->player->character->shape, NULL);
        else
            sfRenderWindow_drawRectangleShape(app->window,
            app->layer, NULL);
        mobs_render_annimation(app);
        if (!app->element->player->front)
            sfRenderWindow_drawRectangleShape(app->window,
            app->layer, NULL);
        else
            sfRenderWindow_drawRectangleShape(app->window,
            app->element->player->character->shape, NULL);
    }
}
