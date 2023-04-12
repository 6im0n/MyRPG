/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** manage
*/

#include <stdio.h>
#include "app/app.h"
#include <SFML/Graphics.h>

static void view_resize(app_t *app, event_t *event)
{
    sfVector2f tmp = {event->original.size.width, event->original.size.height};
    sfVector2f center = {1920 / 2, 1080 / 2};
    sfVector2f center_back = {1920 / 2, 1000 / 2};
    float widht = event->original.size.width / 1920.0;
    float height = event->original.size.height / 1080.0;

    sfView_setSize(app->view, tmp);
    sfView_setCenter(app->view, center);
    if (widht < height)
        sfView_zoom(app->view, 1920.0 / event->original.size.width);
    else
        sfView_zoom(app->view, 1080.0 / event->original.size.height);
    sfView_setSize(app->background, tmp);
    sfView_setCenter(app->background, center_back);
    if (widht > event->original.size.height / 1000.0)
        sfView_zoom(app->background, 1920.0 / event->original.size.width);
    else
        sfView_zoom(app->background, 1000.0 / event->original.size.height);
}

void manage_view(app_t *app, event_t *event, main_components_t *components)
{
    (void) components;
    if (event->original.type == sfEvtResized)
        view_resize(app, event);
}
