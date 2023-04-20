/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** set
*/

#include <SFML/Graphics.h>
#include "components/components.h"
#include "components/new.h"
#include "types/list.h"
#include "ressources/textures.h"
#include "components/get.h"
#include "event/game/global.h"
#include "components/mobs.h"
#include "types/type.h"
#include "parsing/buttons.h"
#include "types/node.h"
#include "app/constants.h"

static void menu_board(ressources_t ressources,
                        list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f middle = {W_VIDEO_MODE.width / 2,W_VIDEO_MODE.height / 2};
    sfVector2f position = {middle.x, middle.y };
    sfVector2f size = {middle.x * 1.9 , middle.y * 1.9};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_IMMORTAL };
    sfColor color = {sfBlack.r, sfBlack.g, sfBlack.b, 0};
    sfColor colort = {136, 8, 8, 255};

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_SIGN, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size, (sfIntRect){.height = 122,
        .left = 139, .top = 12, .width = 106}, C_SIZE_MAX);
    sfRectangleShape_setFillColor(obj->object->rectangle, color);
    set_component_text(obj, "You are dead", colort, 150);
    set_component_text_pos(obj, (sfVector2f){ 0, -200}, 0);
    obj->events.ondisabled = &event_timer_onhover;
    list_component_append(list, obj);
}

static void bouton_back_home(ressources_t ressources,
                        list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f middle = {W_VIDEO_MODE.width / 2,W_VIDEO_MODE.height / 2};
    sfVector2f position = {middle.x, middle.y + 100};
    sfVector2f size = {400 , 100};
    sfFloatRect rect = {.height = size.y, .left = (position.x - size.x),
                        .top = (position.y - size.y), .width = size.x};
    component_styles style = { TX_DIALOG_MENU_BGR, SD_NONE, FT_DROID };
    sfColor color = {sfBlack.r, sfBlack.g, sfBlack.b, 235};

    obj->events = (component_events_t) { NULL };
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size, (sfIntRect){.height = 122,
        .left = 139, .top = 12, .width = 106}, C_SIZE_MAX);
    sfRectangleShape_setFillColor(obj->object->rectangle, color);
    set_component_text(obj, "Back Home", sfWhite, 50);
    set_component_text_pos(obj, (sfVector2f){ 0, -20}, 0);
    obj->events.onclick = &event_death_back_home;
    list_component_append(list, obj);
}

void components_death(app_t *app, ressources_t ressources,
list_components_t *list)
{
    (void) app;
    menu_board(ressources, list);
    bouton_back_home(ressources, list);
}
