/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** append
*/

#include "app/app.h"
#include "types/list.h"
#include "ressources/loaders/fonts.h"
#include "ressources/loaders/popup.h"

static void popup_shape(list_pop_up_t *list, node_popup_t *node)
{
    sfFont *font =
        sfFont_createFromFile(fonts_loaders[FT_DROID]);
    sfVector2f pos = {1910, 1035};
    sfVector2f origin;
    sfFloatRect rect;

    sfText_setColor(node->text, sfBlack);
    sfText_setCharacterSize(node->text, 50);
    sfText_setFont(node->text, font);
    sfText_setLineSpacing(node->text, 0.8);
    rect = sfText_getGlobalBounds(node->text);
    origin.x = rect.width;
    origin.y = rect.height;
    sfText_setOrigin(node->text, origin);
    if (list->len > 0)
        pos.y = sfText_getPosition(list->last->text).y - 50;
    sfText_setPosition(node->text, pos);
}

void new_popup(app_t *app, type_popup_t type, int time)
{
    node_popup_t *node = malloc(sizeof(node_popup_t));

    if (!node)
        return;
    node->clock = sfClock_create();
    node->text = sfText_create();
    sfText_setString(node->text, popup_loaders[type]);
    popup_shape(app->element->pop_up, node);
    node->auto_destroy = time;
    node->next = NULL;
    node->prev = NULL;
    node->type = type;
    list_pop_up_append(app->element->pop_up, node);
}

void list_pop_up_append(list_pop_up_t *list, node_popup_t *node)
{
    if (list->last != NULL) {
        node->next = NULL;
        list->last->next = node;
        node->prev = list->last;
    } else {
        node->next = list->first;
        list->first = node;
        node->prev = NULL;
    }
    list->last = node;
    list->len++;
}
