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

void player_attack(app_t *app)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) ) {
        app->element->player->character->irect.top = 405;
        app->element->player->character->annimation.max = 3;
    }
}