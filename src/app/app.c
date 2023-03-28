/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** app
*/

#include "app/app.h"
#include "types/type.h"
#include "types/renderer.h"
#include "app/constants.h"
#include "app/ressources.h"
#include "components/components.h"

int app_run(void)
{
    ressources_t ressources = ressources_load();
    app_t app = app_create(&ressources, WINDOW_VIDEO_MODE, WINDOW_TITLE, WINDOW_FRAMERATE);
    renderer_objects_t objects = renderer_objects_create(app.window);
    main_components_t components = app_components_load(&app);

    while (sfRenderWindow_isOpen(app.window)) {
        app_render(&app, &ressources, &components);
        app_handle_events(&app);
    }
    components_free(&components);
    ressources_unload(&ressources);
    renderer_objects_destroy(&objects);
    app_destroy(&app);
    return 0;
}
