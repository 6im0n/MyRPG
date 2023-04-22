/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** save
*/

#include "app/app.h"

void save_game_onkeypress(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) component;
    if (!ST_IS_NEAR(component))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyP))
        app_save_game(app);
}
