/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** skill
*/

#include "types/type.h"
#include "components/components.h"
#include "components/popup.h"
#include "app/app.h"

void event_inventory_skill_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    sfRectangleShape *rectangle = component->object->rectangle;
    sfIntRect rect = {97, 194, 14, 12};

    (void) event;
    sfText_setColor(component->object->text, sfTransparent);
    if (app->element->player->exprerience.skill == 0)
        return sfRectangleShape_setTextureRect(rectangle, rect);
    rect.top += 16;
    if (app->element->player->exprerience.skill == 1)
        return sfRectangleShape_setTextureRect(rectangle, rect);
    rect.left += 16;
    if (app->element->player->exprerience.skill == 2)
        return sfRectangleShape_setTextureRect(rectangle, rect);
    rect.left += 16;
    if (app->element->player->exprerience.skill >= 3)
        return sfRectangleShape_setTextureRect(rectangle, rect);
}

static void selector_skill_increment(node_component_t *component,
player_t *player, app_t *app)
{
    switch (component->id) {
        case ID_SKILL_SPEED:
            player->skills.speed += 2;
            new_popup(app, P_WIN_SPEED, 5);
            break;
        case ID_SKILL_STRENGHT:
            player->skills.strength += 2;
            new_popup(app, P_WIN_STRENGHT, 5);
            break;
        case ID_SKILL_RESISTANCE:
            player->skills.resitance += 2;
            new_popup(app, P_WIN_RESISTANCE, 5);
            break;
        default:
            break;
    }
}

void event_inventory_skill_onpressed(node_component_t *component,
event_t *event, app_t *app)
{
    player_t *player = app->element->player;

    (void) event;
    if (player->exprerience.skill <= 0)
        return;
    selector_skill_increment(component, player, app);
    player->exprerience.skill--;
    player->exprerience.update = -1;
    component->state = ST_SET_PRESSED(component, false);
}
