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
#include "lib/output.h"

static void set_new_texture(node_component_t *component)
{
    sfTexture *texture = sfTexture_createFromFile(
        textures_loaders[TX_SHRINE_ACTIVATING], NULL);

    sfRectangleShape_setTexture(component->object->rectangle,
        texture, sfFalse);
    component->annimation.index = 0;
    component->annimation.one = true;
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
        set_new_texture(component);
        healt_give(app->element->player);
    }
}

static void give_random_skill(app_t *app, player_t *player)
{
    int choose = rand() % 3;

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
        give_random_skill(app, app->element->player);
    }
}
