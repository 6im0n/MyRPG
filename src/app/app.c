/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** app
*/

#include "app/app.h"
#include "types/type.h"
#include "app/constants.h"

int app_run(void)
{
    app_t app = app_create(WINDOW_VIDEO_MODE, WINDOW_TITLE, WINDOW_FRAMERATE);

    while (sfRenderWindow_isOpen(app.window)) {
        app_handle_events(&app);
    }
    app_destroy(&app);
    return 0;
}
