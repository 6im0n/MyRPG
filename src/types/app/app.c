/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** app_construction
*/

#include <SFML/Graphics.h>
#include "app/app.h"
#include "types/type.h"
#include "app/constants.h"
#include "components/player.h"
#include "components/mobs.h"
#include "types/list.h"
#include "lib/output.h"
#include "components/popup.h"

app_t app_create(char *window_title, int window_frame_rate)
{
    sfRenderWindow *window = sfRenderWindow_create(
        sfVideoMode_getDesktopMode(), window_title,
        sfFullscreen, NULL
    );
    mouse_t mouse = mouse_init();
    state_t *state = state_new();
    sfView *view = sfView_create();
    sfView *background = sfView_create();
    sfRectangleShape *layer = sfRectangleShape_create();
    loader_t *loader = loader_init();
    app_t app = { window, mouse, state, background,
                    view, layer, NULL, loader };

    sfRenderWindow_setFramerateLimit(app.window, window_frame_rate);
    sfRenderWindow_clear(app.window, W_COLOR);
    sfRenderWindow_setMouseCursorVisible(app.window, sfFalse);
    loader_display(&app, app.loader->shape);
    loader_display(&app, app.loader->cursor);
    loader_display(&app, app.loader->logo);
    return (app);
}

void app_destroy(app_t *app)
{
    if (app) {
        list_pop_up_free(app->element->pop_up);
        free(app->loader);
        list_quests_free(app->element->quests);
        player_destroy(app->element->player);
        list_item_free(app->element->items);
        free(app->element);
        state_free(app->state);
        sfRenderWindow_destroy(app->window);
    }
}
