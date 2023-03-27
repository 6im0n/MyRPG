/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** app
*/

#include "app/app.h"
#include "types/type.h"
#include "app/constants.h"
#include "app/ressources.h"

int app_run(void)
{
    ressources_t ressources = ressources_load();
    app_t app = app_create(&ressources, WINDOW_VIDEO_MODE, WINDOW_TITLE, WINDOW_FRAMERATE);

    while (sfRenderWindow_isOpen(app.window)) {
        app_render(&app, &ressources);
        app_handle_events(&app);
    }
    ressources_unload(&ressources);
    app_destroy(&app);
    return 0;
}
