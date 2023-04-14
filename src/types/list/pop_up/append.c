/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** append
*/

#include "app/app.h"
#include "types/list.h"
#include "ressources/loaders/textures.h"
#include "ressources/loaders/fonts.h"
#include "ressources/loaders/popup.h"

static void popup_shape(list_pop_up_t *list, node_popup_t *node)
{
    sfTexture *texture =
        sfTexture_createFromFile(textures_loaders[TX_DIALOG_MENU_BGR], NULL);
    sfFont *font =
        sfFont_createFromFile(fonts_loaders[FT_DROID]);
    sfVector2f pos = {1275, 450};

    sfRectangleShape_setTexture(node->shape, texture, sfFalse);
    sfRectangleShape_setTextureRect(node->shape,
        (sfIntRect){.height = 122, .left = 139, .top = 12, .width = 106});
    sfRectangleShape_setSize(node->shape, (sfVector2f){450, 200});
    sfText_setColor(node->text, sfBlack);
    sfText_setFont(node->text, font);
    sfText_setLineSpacing(node->text, 0.8);
    if (list->len >= 1)
        pos.y = sfRectangleShape_getPosition(list->last->shape).y + 220;
    sfRectangleShape_setPosition(node->shape, pos);
}

void new_popup(app_t *app, type_popup_t type, int time)
{
    node_popup_t *node = malloc(sizeof(node_popup_t));

    if (!node)
        return;
    node->clock = sfClock_create();
    node->shape = sfRectangleShape_create();
    node->text = sfText_create();
    popup_shape(app->element->pop_up, node);
    sfText_setString(node->text, popup_loaders[type]);
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
