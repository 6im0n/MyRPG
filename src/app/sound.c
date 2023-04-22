/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** sound
*/

#include <stdio.h>
#include "app/ressources.h"

void play_sounds(app_t *app)
{
    if (app->element->player->life < 4 && !app->element->player->playing) {
        sfSound_play(app->element->player->heart);
        app->element->player->playing = true;
    }
    if (app->element->player->life > 3) {
        app->element->player->playing = false;
        sfSound_stop(app->element->player->heart);
    }
}
