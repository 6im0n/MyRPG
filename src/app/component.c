/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** Get componenent
*/

#include <stdlib.h>
#include "types/types.h"
#include "types/list.h"
#include "components/components.h"
#include "components/get.h"
#include "event/inventory/bouton.h"
#include "event/setting/bouton.h"
#include "event/start_menu/bouton.h"

static void append_menu_start(app_t *app, ressources_t ressources,
renderer_objects_t objects, main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *fstart_menu = component_pure_new(size);
    list_components_t *mstart_menu = list_components_init();

    mstart_menu->id = S_MENU_START;
    fstart_menu->events.onkeypress = &event_menu_onkeypress;
    list_component_append(mstart_menu, fstart_menu);
    components->start_menu = mstart_menu;
    components_get_start_menu(app, ressources, objects, mstart_menu);
}

static void append_menu_help(app_t *app, ressources_t ressources,
renderer_objects_t objects, main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *fhelp_menu = component_pure_new(size);
    list_components_t *mhelp_menu = list_components_init();

    mhelp_menu->id = S_MENU_HELP;
    fhelp_menu->events.onkeypress = &event_menu_help_onkeypress;
    list_component_append(mhelp_menu, fhelp_menu);
    components->help_menu = mhelp_menu;
    components_get_help_menu(app, ressources, objects, mhelp_menu);
}

static void append_inventory(app_t *app, ressources_t ressources,
renderer_objects_t objects, main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *finventory = component_pure_new(size);
    list_components_t *minventory = list_components_init();

    minventory->id = S_INVENTORY;
    finventory->events.onkeypress = &event_key_inventory_close_onkeypressed;
    list_component_append(minventory, finventory);
    components->inventory = minventory;
    components_get_inventory(app, ressources, objects, minventory);
}

static void append_settings(app_t *app, ressources_t ressources,
renderer_objects_t objects, main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *fsetting = component_pure_new(size);
    list_components_t *msetting = list_components_init();

    msetting->id = S_SETTINGS;
    fsetting->events.onkeypress = &event_key_settings_close_onkeypressed;
    list_component_append(msetting, fsetting);
    components->setting = msetting;
    components_get_setting(app, ressources, objects, msetting);
}

main_components_t app_components_load(app_t *app, ressources_t ressources,
renderer_objects_t objects)
{
    main_components_t components = { NULL, NULL, NULL, NULL, NULL };

    append_menu_start(app, ressources, objects, &components);
    append_menu_help(app, ressources, objects, &components);
    append_inventory(app, ressources, objects, &components);
    append_settings(app, ressources, objects, &components);
    return components;
}
