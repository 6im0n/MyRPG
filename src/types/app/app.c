/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** app_construction
*/

#include <SFML/Graphics.h>
#include "app/app.h"
#include "types/type.h"
#include "app/constants.h"

app_t app_create(sfVideoMode window_mode, char *window_title,
int window_frame_rate)
{
    sfRenderWindow *window = sfRenderWindow_create(
        window_mode, window_title,
        sfResize | sfClose, NULL
    );
    app_t app = { window };

    app_set_icon(app.window);
    sfRenderWindow_setFramerateLimit(app.window, window_frame_rate);
    sfRenderWindow_clear(app.window, WINDOW_COLOR);
    return (app);
}

void app_destroy(app_t *app)
{
    if (app) {
        sfRenderWindow_destroy(app->window);
    }
}
