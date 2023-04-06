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
#include "event/start_menu/bouton.h"
#include "event/setting/bouton.h"
#include "event/global.h"
#include "lib/output.h"

static void bouton_newgame(app_t *app, ressources_t ressources,
                            list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 - 250,
        sfRenderWindow_getSize(app->window).y / 2};
    sfVector2f size = {340, 90};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_GRAB, FT_DROID };

    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 27, .left = 163, .top = 178, .width = 90},
        C_SIZE_BIG);
    set_component_text(obj, "New Game", sfBlack, 40);
    set_component_text_pos(obj, (sfVector2f){ 0, -12}, 0);
    list_component_append(list, obj);
}

static void launch_game(node_component_t *component,
event_t *event, app_t *app)
{
    (void) component;
    (void) event;
    event_play_music(component, app);
    app->state->back = app->state->stage;
    app->state->stage = S_GAME;
}

static void bouton_resume(app_t *app, ressources_t ressources,
                            list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2 + 250,
        sfRenderWindow_getSize(app->window).y / 2};
    sfVector2f size = {340, 90};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_GRAB, FT_DROID };

    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 27, .left = 163, .top = 178, .width = 90},
        C_SIZE_BIG);
    set_component_text(obj, "Resume", sfBlack, 40);
    set_component_text_pos(obj, (sfVector2f){ 0, -12}, 0);
    obj->events.onclick = &launch_game;
    list_component_append(list, obj);
}

static void bouton_home(app_t *app, ressources_t ressources,
                        list_components_t *list)
{
    node_component_t *obj = malloc(sizeof(node_component_t));
    sfVector2f position = {sfRenderWindow_getSize(app->window).x / 2,
        sfRenderWindow_getSize(app->window).y / 2};
    sfVector2f size = {50, 50};
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
        .top = (position.y - (size.y / 2)), .width = size.x};
    component_styles style = { TX_MENU_ALL, SD_GRAB, FT_DROID };

    (void) app;
    new_component_set(obj, rect, C_TYPES_BTN_TXT, style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size,
        (sfIntRect){.height = 24, .left = 773, .top = 68, .width = 22},
        C_SIZE_SMALL);
    set_component_text(obj, "Home", sfTransparent, 30);
    set_component_text_pos(obj, (sfVector2f){ 0, 15}, 3);
    obj->events.onclick = &event_help_bouton_home_onclick;
    obj->events.onhover = &event_bouton_help_onhover;
    obj->events.ondisabled = &event_bouton_help_ondisabled;
    list_component_append(list, obj);
}

void component_load_game_bouton(app_t *app, ressources_t ressources,
                                list_components_t *list)
{
    bouton_newgame(app, ressources, list);
    bouton_resume(app, ressources, list);
    bouton_home(app, ressources, list);
}
