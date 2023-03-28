/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** render
*/

#include "types/types.h"
#include "app/app.h"
#include "app/ressources.h"
#include "app/constants.h"
#include <SFML/Graphics.h>

void app_render(app_t *app, ressources_t *ressources)
{
    (void) ressources;
    sfRenderWindow_clear(app->window, WINDOW_COLOR);
    sfRenderWindow_display(app->window);
}
