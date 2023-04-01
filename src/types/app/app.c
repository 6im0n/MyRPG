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

app_t app_create(ressources_t *ressources, sfVideoMode window_mode,
char *window_title, int window_frame_rate)
{
    sfRenderWindow *window = sfRenderWindow_create(
        window_mode, window_title,
        sfResize | sfClose, NULL
    );
    mouse_t mouse = mouse_init();
    state_t *state = state_new();
    app_t app = { window, mouse, state };

    app_set_icon(app.window, ressources);
    sfRenderWindow_setFramerateLimit(app.window, window_frame_rate);
    sfRenderWindow_clear(app.window, W_COLOR);
    sfRenderWindow_setMouseCursorVisible(app.window, sfFalse);
    return (app);
}

void app_destroy(app_t *app)
{
    if (app) {
        state_free(app->state);
        sfRenderWindow_destroy(app->window);
    }
}
