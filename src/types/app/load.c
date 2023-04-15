/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** load
*/

#include "app/app.h"
#include "types/type.h"
#include "types/renderer.h"
#include "app/constants.h"
#include "app/ressources.h"
#include "components/components.h"
#include "types/list.h"

static void set_music(ressources_t *ressources, app_t *app)
{
    sfSound_setBuffer(app->state->sound->music,
        ressources->sounds[SD_EXPLORATION]);
    sfSound_setLoop(app->state->sound->music, sfTrue);
    sfSound_play(app->state->sound->music);
}

static elements_t *element_create(ressources_t *ressources)
{
    elements_t *element = malloc(sizeof(elements_t));
    player_t *player = player_create(ressources);
    node_item_t *fitem = item_pure_new();
    list_item_t *items = list_item_init();
    list_quests_t *quest = list_quests_init();

    list_item_append(items, fitem);
    element->player = player;
    element->items = items;
    element->quests = quest;
    return element;
}

static void player_set_view(elements_t *element, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f view_size = {window_size.x / 3.8, window_size.y / 3.8};

    sfView_setSize(element->player->view, view_size);
}

void app_load(app_t *app, ressources_t *ressources)
{
    elements_t *element = element_create(ressources);

    app->element = element;
    player_set_view(element, app->window);
    set_music(ressources, app);
    app_create_all_item(app->element, ressources);
    app_set_icon(app->window, ressources);
}
