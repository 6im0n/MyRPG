/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** death
*/

#include "types/type.h"

static void death_alpha(list_pop_up_t *list, node_popup_t *node)
{
    sfColor color = sfText_getColor(node->text);
    sfTime elapsed = sfClock_getElapsedTime(node->clock);

    if (sfTime_asSeconds(elapsed) >= node->auto_destroy - 2 && color.a > 0) {
        color.a--;
        sfText_setColor(node->text, color);
    }
    if (sfTime_asSeconds(elapsed) >= node->auto_destroy) {
        delete(list, node);
    }
}

void death_render(app_t *app, main_components_t *components)
{
    
}
