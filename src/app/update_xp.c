/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** events
*/

#include <math.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include "app/app.h"
#include "components/view.h"
#include "components/player.h"
#include "event/game/global.h"
#include "components/misc/events.h"
#include "event/levels.h"


void update_xp(app_t *app, main_components_t *components)
{
    if (app->element->player->exprerience.update != 0) {
        levels_update(app, components->inventory,
        app->element->player->exprerience.update);
        app->element->player->exprerience.update = 0;
    }
}
