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
#include "types/list.h"
#include "lib/output.h"

static void set_music(ressources_t *ressources, app_t *app)
{
    sfSound_setBuffer(app->state->sound->music,
        ressources->sounds[SD_EXPLORATION]);
    sfSound_setLoop(app->state->sound->music, sfTrue);
    sfSound_play(app->state->sound->music);
}

static elements_t *element_create(ressources_t *ressources)
{
    elements_t *element = malloc(sizeof(elements_t));
    player_t *player = player_create(ressources);
    node_item_t *fitem = item_pure_new();
    list_item_t *items = list_item_init();

    list_item_append(items, fitem);
    element->player = player;
    element->items = items;
    return element;
}

static void player_set_view(elements_t *element, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f view_size = {window_size.x / 2, window_size.y / 2};

    sfView_setSize(element->player->view, view_size);
}

app_t app_create(ressources_t *ressources, sfVideoMode window_mode,
char *window_title, int window_frame_rate)
{
    sfRenderWindow *window = sfRenderWindow_create(
        window_mode, window_title,
        sfResize | sfClose, NULL
    );
    mouse_t mouse = mouse_init();
    state_t *state = state_new();
    sfView *view = sfView_create();
    elements_t *element = element_create(ressources);
    app_t app = { window, mouse, state, view, element };

    app_create_all_item(app.element, ressources);
    app_set_icon(app.window, ressources);
    player_set_view(element, window);
    sfRenderWindow_setFramerateLimit(app.window, window_frame_rate);
    sfRenderWindow_clear(app.window, W_COLOR);
    sfRenderWindow_setMouseCursorVisible(app.window, sfFalse);
    set_music(ressources, &app);
    return (app);
}

void app_destroy(app_t *app)
{
    if (app) {
        player_destroy(app->element->player);
        list_item_free(app->element->items);
        free(app->element);
        state_free(app->state);
        sfRenderWindow_destroy(app->window);
    }
}
