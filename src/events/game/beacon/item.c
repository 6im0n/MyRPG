/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** item
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

void beacon_item_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    int random = rand() % I_LEN;

    if (random == 0)
        random++;
    (void) event;
    if (!ST_IS_NEAR(component) || component->features.select)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        new_popup(app, P_ITEM, 5);
        component->features.select = true;
        set_new_texture(component, TX_SHRINE_L_ACTIVATING, true);
        component->annimation.clock = sfClock_create();
        add_item_player(app, random);
    }
}

void beacon_item_events_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    sfTime time;

    (void) event;
    (void) app;
    if (component->features.select == false)
        return;
    time = sfClock_getElapsedTime(component->annimation.clock);
    if (sfTime_asSeconds(time) > (60 * 4)) {
        component->annimation.index = 0;
        component->annimation.speed = 0;
        if (component->id == ID_SHRINE) {
            set_new_texture(component, TX_SHRINE_L_AVAILABLE, false);
            component->annimation.speed = component->annimation.max_speed;
        }
        component->features.select = false;
        sfClock_destroy(component->annimation.clock);
        sfRectangleShape_setTextureRect(component->object->rectangle,
            component->features.texture_rect);
    }
}
