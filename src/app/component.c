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

static void append_menu_load_game(app_t *app, ressources_t ressources,
main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *fload_game = component_pure_new(size);
    list_components_t *mload_game = list_components_init();

    mload_game->id = S_MENU_LOAD_GAME;
    fload_game->events.onkeypress = &event_menu_onkeypress;
    list_component_append(mload_game, fload_game);
    components->load_game = mload_game;
    components_get_load_game(app, ressources, mload_game);
}

static void append_inventory(app_t *app, ressources_t ressources,
                            main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *finventory = component_pure_new(size);
    list_components_t *minventory = list_components_init();

    minventory->id = S_INVENTORY;
    finventory->events.onkeypress = &event_key_inventory_close_onkeypressed;
    list_component_append(minventory, finventory);
    components->inventory = minventory;
    components_get_inventory(app, ressources, minventory);
}

static void append_cursor(app_t *app, ressources_t ressources,
                            main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *fcursor = component_pure_new(size);
    list_components_t *mcursor = list_components_init();

    mcursor->id = S_CURSOR;
    list_component_append(mcursor, fcursor);
    components->cursor = mcursor;
    components_get_cursor(app, ressources, mcursor);
}

main_components_t app_components_load(app_t *app, ressources_t ressources)
{
    main_components_t components = { NULL, NULL, NULL,
        NULL, NULL, NULL, NULL };

    append_menu(app, ressources, &components);
    append_cursor(app, ressources, &components);
    append_menu_load_game(app, ressources, &components);
    append_inventory(app, ressources, &components);
    return components;
}
