/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** append
*/

#include "lib/tools.h"
#include "types/list.h"
#include "ressources/loaders/quests.h"
#include "ressources/loaders/textures.h"
#include "ressources/loaders/fonts.h"
#include "app/app.h"

void quest_append(app_t *app, quests_t quest)
{
    list_quests_t *list = app->element->quests;
    node_quests_t *q_main_1 = list_node_qest_append(quest, list);
    node_quests_t *tmp = list->first;

    while (tmp != NULL) {
        if (tmp->id == quest)
            return;
        tmp = tmp->next;
    }
    list_quest_append(list, q_main_1);
    new_popup(app, P_QUESTS, 5);
}

static void set_text_quest(quests_t quests, node_quests_text_t *text)
{
    text->title = quests_loaders[quests][TQ_TITLE];
    text->description = quests_loaders[quests][TQ_DESCRIPTION];
    text->detail = quests_loaders[quests][TQ_DETAIL];
    text->objectif = quests_loaders[quests][TQ_OBJECTIF];
    text->reward = quests_loaders[quests][TQ_REWARD];
}

static void set_shape(node_quests_t *node, list_quests_t *list)
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
    sfText_setColor(node->txt, sfBlack);
    sfText_setFont(node->txt, font);
    sfText_setLineSpacing(node->txt, 0.8);
    if (list->len >= 1)
        pos.y = sfRectangleShape_getPosition(list->last->shape).y + 220;
    sfRectangleShape_setPosition(node->shape, pos);
}

node_quests_t *list_node_qest_append(quests_t quests, list_quests_t *list)
{
    node_quests_t *node = malloc(sizeof(node_quests_t));
    node_quests_text_t *text = malloc(sizeof(node_quests_text_t));

    node->shape = sfRectangleShape_create();
    node->txt = sfText_create();
    if (!node || !text)
        return NULL;
    node->next = NULL;
    node->prev = NULL;
    node->current = 0;
    node->finish = false;
    node->goal = quests_loaders_goal[quests];
    node->id = quests;
    set_shape(node, list);
    set_text_quest(quests, text);
    node->text = text;
    return node;
}

void list_quest_append(list_quests_t *list, node_quests_t *node)
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
