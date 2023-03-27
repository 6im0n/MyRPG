/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** events
*/

#include <stdio.h>
#include "app/app.h"
#include "types/types.h"
#include <SFML/Graphics.h>

void app_handle_events(app_t *app)
{
    event_t event;

    while (sfRenderWindow_pollEvent(app->window, &(event.original))) {
        if (event.original.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
    }
}
