/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** manage
*/

#include "app/app.h"
#include <SFML/Graphics.h>

static void view_resize(app_t *app, event_t *event)
{
    sfVector2f tmp = {event->original.size.width, event->original.size.height};
    sfVector2f center = {tmp.x / 2, tmp.y / 2};

    sfView_setSize(app->view, tmp);
    sfView_setCenter(app->view, center);
}

void manage_view(app_t *app, event_t *event, main_components_t *components)
{
    (void) components;
    if (event->original.type == sfEvtResized)
        view_resize(app, event);
}
