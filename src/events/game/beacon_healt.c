/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** beacon_healt
*/

#include "types/type.h"
#include "components/components.h"
#include "event/global.h"
#include "types/list.h"
#include "app/app.h"
#include "ressources/loaders/textures.h"
#include <stdlib.h>
#include <stdio.h>
#include "event/levels.h"

static void set_new_texture(node_component_t *component,
texture_t tx, bool active)
{
    sfTexture *texture = sfTexture_createFromFile(textures_loaders[tx], NULL);

    sfRectangleShape_setTexture(component->object->rectangle,
        texture, sfFalse);
    component->annimation.index = 0;
    component->annimation.one = active;
}

void healt_give(player_t *player)
{
    player->life += 4;
    if (player->life > 10)
        player->life = 10;
}

void beacon_healt_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    if (!ST_IS_NEAR(component) || component->features.select)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        new_popup(app, P_HEALT, 5);
        component->features.select = true;
        set_new_texture(component, TX_SHRINE_ACTIVATING, true);
        component->annimation.clock = sfClock_create();
        healt_give(app->element->player);
    }
}

static void give_random_skill(app_t *app, player_t *player)
{
    int choose = rand() % 4;

    switch (choose) {
        case 0:
            player->skills.speed += 3;
            break;
        case 1:
            player->skills.strength += 3;
            break;
        case 2:
            player->skills.resitance += 3;
            break;
        case 3:
            player->exprerience.update += 500;
            break;
        default:
            break;
    }
    new_popup(app, (P_WIN_SPEED + choose), 5);
}

void beacon_skill_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    if (!ST_IS_NEAR(component) || component->features.select)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        component->features.select = true;
        component->annimation.speed = 0.1;
        component->annimation.index = 0;
        component->annimation.one = true;
        component->annimation.clock = sfClock_create();
        give_random_skill(app, app->element->player);
    }
}

void beacon_events_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    sfTime time;

    (void) event;
    (void) app;
    if (component->features.select == false)
        return;
    time = sfClock_getElapsedTime(component->annimation.clock);
    if (sfTime_asSeconds(time) > (2)) {
        component->annimation.index = 0;
        component->annimation.speed = 0;
        if (component->id == ID_SHRINE) {
            set_new_texture(component, TX_SHRINE_AVAILABLE, false);
            component->annimation.speed = component->annimation.max_speed;
        }
        component->features.select = false;
        sfClock_destroy(component->annimation.clock);
        sfRectangleShape_setTextureRect(component->object->rectangle,
            component->features.texture_rect);
    }
}
