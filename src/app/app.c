/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** app
*/

#include "app/app.h"
#include "types/type.h"
#include "types/renderer.h"
#include "app/constants.h"
#include "app/ressources.h"
#include "components/components.h"
#include "types/list.h"
#include "lib/output.h"

static void game_set_layer(app_t *app, ressources_t *ressources)
{
    sfRectangleShape_setTexture(app->layer, ressources->textures[TX_LAYER],
        sfFalse);
    sfRectangleShape_setSize(app->layer, (sfVector2f){
        sfImage_getSize(app->element->player->collisions).x,
        sfImage_getSize(app->element->player->collisions).y});
}

static void dev_add_item_inv(app_t *app)
{
    add_item_player(app, I_HAMMER_LEV1);
    add_item_player(app, I_HAMMER_LEV2);
    add_item_player(app, I_HAMMER_LEV3);
    add_item_player(app, I_HAMMER_LEV4);
}

int app_run(void)
{
    ressources_t ressources = ressources_load();
    app_t app = app_create(&ressources, W_VIDEO_MODE, W_TITLE, W_FRAMERATE);
    main_components_t components = app_components_load(&app, ressources);

    dev_add_item_inv(&app);
    game_set_layer(&app, &ressources);
    while (sfRenderWindow_isOpen(app.window)) {
        app_render(&app, &ressources, &components);
        app_handle_events(&app, &components);
    }
    components_free(&components);
    ressources_unload(&ressources);
    app_destroy(&app);
    return 0;
}
