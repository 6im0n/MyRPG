/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** app
*/

#include <stdio.h>
#include "app/app.h"
#include "types/type.h"
#include "types/renderer.h"
#include "app/constants.h"
#include "app/ressources.h"
#include "components/components.h"
#include "types/list.h"
#include "lib/output.h"
#include "event/levels.h"

static void happy_moulinette(void)
{
    sfSprite *dumb_sprite = sfSprite_create();

    sfSprite_destroy(dumb_sprite);
}

static void game_set_layer(app_t *app, ressources_t *ressources)
{
    sfRectangleShape_setTexture(app->layer, ressources->textures[TX_LAYER],
        sfFalse);
    sfRectangleShape_setSize(app->layer, (sfVector2f){
        sfImage_getSize(app->element->player->collisions).x,
        sfImage_getSize(app->element->player->collisions).y});
}

void clear_component(list_components_t *list)
{
    node_component_t *node = list->first;

    while (node) {
        node->features.select = false;
        node->features.visited = 0;
        node = node->next;
    }
}

int app_run(void)
{
    app_t app = app_create(W_TITLE, W_FRAMERATE);
    ressources_t ressources = ressources_load(&app);
    main_components_t components = app_components_load(&app, ressources);

    happy_moulinette();
    game_set_layer(&app, &ressources);
    levels_update(&app, components.inventory, 0);
    while (sfRenderWindow_isOpen(app.window)) {
        app_render(&app, &ressources, &components);
        app_handle_events(&app, &components);
        if (app.first) {
            clear_component(components.game);
            app.first = false;
        }
    }
    components_free(&components);
    ressources_unload(&ressources);
    app_destroy(&app);
    return 0;
}
