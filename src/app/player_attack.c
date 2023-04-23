/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player attack
*/

#include <SFML/Graphics.h>
#include "app/app.h"
#include "components/view.h"
#include "components/player.h"
#include "event/game/global.h"
#include "components/misc/events.h"

void update_old_key(app_t *app, int id)
{
    app->element->player->character->key.old_key = id;
    if (app->element->player->character->key.old_key == 5)
        app->element->player->character->key.old_key = 3;
    if (app->element->player->character->key.old_key == 6)
        app->element->player->character->key.old_key = 3;
    if (app->element->player->character->key.old_key == 7)
        app->element->player->character->key.old_key = 4;
    if (app->element->player->character->key.old_key == 8)
        app->element->player->character->key.old_key = 4;
}

bool finish_attack_player(app_t *app)
{
    if (app->element->player->character->annimation.index >
            app->element->player->character->annimation.max &&
            app->element->player->character->state.attack) {
        app->element->player->character->annimation.index = 0;
        app->element->player->character->state.attack = false;
        app->element->player->character->irect.top = 20;
        return true;
    } else if (app->element->player->character->state.attack)
        return false;
    else
        return true;
}

static void attack_animation_update(app_t *app)
{
    int old_key = app->element->player->character->key.old_key;
    switch (old_key) {
        case 1:
            app->element->player->character->irect.top = 453;
            app->element->player->character->annimation.max = 3;
            break;
        case 2:
            app->element->player->character->irect.top = 309;
            app->element->player->character->annimation.max = 3;
            break;
        case 3:
            app->element->player->character->irect.top = 405;
            app->element->player->character->annimation.max = 3;
            break;
        case 4:
            app->element->player->character->irect.top = 597;
            app->element->player->character->annimation.max = 3;
            break;
    }
}

void player_attack(app_t *app)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)){
        app->element->player->character->annimation.index = 0;
        app->element->player->character->state.attack = true;
        attack_animation_update(app);
    }
}
