/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** component_extra
*/

#include "app/app.h"
#include "types/list.h"
#include "components/components.h"
#include "components/get.h"
#include "event/inventory/bouton.h"
#include "event/setting/bouton.h"
#include "event/start_menu/bouton.h"
#include "event/game/global.h"

void append_death(app_t *app, ressources_t ressources,
main_components_t *components)
{
    sfVector2u size = sfRenderWindow_getSize(app->window);
    node_component_t *fdeath = component_pure_new(size);
    list_components_t *mdeath = list_components_init();

    mdeath->id = S_DEATH;
    fdeath->events.onkeypress = &event_game_onkeypress;
    fdeath->events.onkeyrelease = &event_key_switch;
    list_component_append(mdeath, fdeath);
    components->death = mdeath;
    components_get_death(app, ressources, mdeath);
}
