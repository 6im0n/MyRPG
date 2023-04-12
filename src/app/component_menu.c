/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Get componenent
*/

#include <stdlib.h>
#include "types/list.h"
#include "components/components.h"
#include "components/get.h"
#include "event/inventory/bouton.h"
#include "event/setting/bouton.h"
#include "event/start_menu/bouton.h"
#include "event/game/global.h"

static void append_menu_start(app_t *app, ressources_t ressources,
                                main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *fstart_menu = component_pure_new(size);
    list_components_t *mstart_menu = list_components_init();

    mstart_menu->id = S_MENU_START;
    fstart_menu->events.onkeypress = &event_menu_onkeypress;
    list_component_append(mstart_menu, fstart_menu);
    components->start_menu = mstart_menu;
    components_get_start_menu(app, ressources, mstart_menu);
}

static void append_menu_help(app_t *app, ressources_t ressources,
main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *fhelp_menu = component_pure_new(size);
    list_components_t *mhelp_menu = list_components_init();

    mhelp_menu->id = S_MENU_HELP;
    fhelp_menu->events.onkeypress = &event_menu_help_onkeypress;
    fhelp_menu->events.onkeyrelease = &event_menu_help_onkeyrelease;
    list_component_append(mhelp_menu, fhelp_menu);
    components->help_menu = mhelp_menu;
    components_get_help_menu(app, ressources, mhelp_menu);
}

static void append_settings(app_t *app, ressources_t ressources,
main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *fsetting = component_pure_new(size);
    list_components_t *msetting = list_components_init();

    msetting->id = S_SETTINGS;
    fsetting->events.onkeypress = &event_key_settings_close_onkeypressed;
    list_component_append(msetting, fsetting);
    components->setting = msetting;
    components_get_setting(app, ressources, msetting);
}

static void append_new_game(app_t *app, ressources_t ressources,
main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *fnew_game = component_pure_new(size);
    list_components_t *mnew_game = list_components_init();

    mnew_game->id = S_NEW_GAME;
    fnew_game->events.onkeypress = &event_game_onkeypress;
    fnew_game->events.onkeyrelease = &event_key_switch;
    list_component_append(mnew_game, fnew_game);
    components->new_game = mnew_game;
    components_get_new_game(app, ressources, mnew_game);
}

void append_menu(app_t *app, ressources_t ressources,
main_components_t *components)
{
    append_menu_start(app, ressources, components);
    append_menu_help(app, ressources, components);
    append_settings(app, ressources, components);
    append_new_game(app, ressources, components);
}
