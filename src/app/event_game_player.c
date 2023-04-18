/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** event_game_player
*/

#include <math.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "components/view.h"
#include "components/player.h"
#include "event/game/global.h"
#include "components/misc/events.h"

static sfVector2f change_animation_direction_diagonally(app_t *app,
sfVector2f pos, float move, int id)
{
    switch (id) {
    case 5:
        pos = (sfVector2f){pos.x + sin(45) * move, pos.y - cos(45) * move};
        app->element->player->character->irect.top = 212;
        break;
    case 6:
        pos = (sfVector2f){pos.x + sin(45) * move, pos.y + cos(45) * move};
        app->element->player->character->irect.top = 212;
        break;
    case 7:
        pos = (sfVector2f){pos.x - sin(45) * move, pos.y - cos(45) * move};
        app->element->player->character->irect.top = 357;
        break;
    case 8:
        pos = (sfVector2f){pos.x - sin(45) * move, pos.y + cos(45) * move};
        app->element->player->character->irect.top = 357;
        break;
    }
    return pos;
}

sfVector2f change_animation_direction(app_t *app, sfVector2f pos, float move,
int id)
{
    switch (id) {
    case 1:
        pos.y -= move;
        app->element->player->character->irect.top = 260;
        break;
    case 2:
        pos.y += move;
        app->element->player->character->irect.top = 164;
        break;
    case 3:
        pos.x += move;
        app->element->player->character->irect.top = 212;
        break;
    case 4:
        pos.x -= move;
        app->element->player->character->irect.top = 357;
        break;
    }
    pos = change_animation_direction_diagonally(app, pos, move, id);
    return pos;
}
