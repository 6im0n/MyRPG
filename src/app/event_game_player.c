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
    update_old_key(app, id);
    return pos = change_animation_direction_diagonally(app, pos, move, id);
}

sfVector2f move_player_on_wall_horizontal(float move,
    sfVector2f position, app_t *app, bool *array)
{
    key_player_t key = app->element->player->character->key;
    move *= 0.5;

    if (key.up && key.right && !array[0] && array[2] && !key.down) {
        position = change_animation_direction(app, position, move, 3);
    }
    if (key.up && key.left && !array[0] && array[3] && !key.down) {
        position = change_animation_direction(app, position, move, 4);
    }
    if (key.down && key.left && !array[1] && array[3] && !key.up) {
        position = change_animation_direction(app, position, move, 4);
    }
    if (key.down && key.right && !array[1] && array[2] && !key.up) {
        position = change_animation_direction(app, position, move, 3);
    }
    return position;
}

sfVector2f move_player_on_wall_vertical(float move,
    sfVector2f position, app_t *app, bool *array)
{
    key_player_t key = app->element->player->character->key;
    move *= 0.5;

    if (key.up && key.right && array[0] && !array[2] && !key.down) {
        position = change_animation_direction(app, position, move, 1);
    }
    if (key.up && key.left && array[0] && !array[3] && !key.down) {
        position = change_animation_direction(app, position, move, 1);
    }
    if (key.down && key.left && array[1] && !array[3] && !key.up) {
        position = change_animation_direction(app, position, move, 2);
    }
    if (key.down && key.right && array[1] && !array[2] && !key.up) {
        position = change_animation_direction(app, position, move, 2);
    }
    return position;
}
