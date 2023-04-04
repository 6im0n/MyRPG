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
#include "lib/output.h"


int app_run(void)
{
    ressources_t ressources = ressources_load();
    app_t app = app_create(&ressources, W_VIDEO_MODE, W_TITLE, W_FRAMERATE);
    main_components_t components = app_components_load(&app, ressources);

    while (sfRenderWindow_isOpen(app.window)) {
        app_render(&app, &ressources, &components);
        app_handle_events(&app, &components);
    }
    components_free(&components);
    ressources_unload(&ressources);
    app_destroy(&app);
    return 0;
}
