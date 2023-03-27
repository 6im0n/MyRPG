/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** render
*/

#include "types/types.h"
#include "app/app.h"
#include "app/ressources.h"
#include "app/constants.h"
#include "components/components.h"
#include <SFML/Graphics.h>

void app_render(app_t *app, ressources_t *ressources, main_components_t *components)
{
    (void) ressources;
    (void) components;
    sfRenderWindow_clear(app->window, WINDOW_COLOR);
    sfRenderWindow_display(app->window);
}
