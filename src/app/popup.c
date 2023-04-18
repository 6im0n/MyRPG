/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** popup
*/

#include "app/app.h"
#include "app/constants.h"
#include "app/ressources.h"
#include "components/mobs.h"
#include "components/view.h"
#include "components/player.h"
#include "components/components.h"

static void delete(list_pop_up_t *list, node_popup_t *node)
{
    if (list->len == 1) {
        list->first = NULL;
        list->last = NULL;
        list->len = 0;
    } else {
        list->first = node->next;
        list->first->prev = NULL;
        list->len--;
    }
}

static void popup_alpha(list_pop_up_t *list, node_popup_t *node)
{
    sfColor color = sfText_getColor(node->text);
    sfTime elapsed = sfClock_getElapsedTime(node->clock);

    if (sfTime_asSeconds(elapsed) >= node->auto_destroy - 3) {
        color.a--;
        sfText_setColor(node->text, color);
    }
    if (sfTime_asSeconds(elapsed) >= node->auto_destroy) {
        delete(list, node);
    }
}

void popup_render(app_t *app)
{
    node_popup_t *tmp = app->element->pop_up->first;
    node_popup_t *tmp2 = tmp;

    while (tmp != NULL) {
        tmp2 = tmp->next;
        popup_alpha(app->element->pop_up, tmp);
        sfRenderWindow_drawText(app->window, tmp->text, NULL);
        tmp = tmp2;
    }
}
