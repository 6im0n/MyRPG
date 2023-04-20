/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** append
*/

#include "app/app.h"
#include "types/list.h"
#include "ressources/loaders/fonts.h"
#include "ressources/loaders/textures.h"
#include "ressources/loaders/speech.h"
#include "components/speech.h"

static sfText *speech_text(sfVector2f pos,
speech_id_t id, speech_style_t style)
{
    sfText *text = sfText_create();
    sfFont *font =
        sfFont_createFromFile(fonts_loaders[FT_DROID]);
    sfVector2f origin = {0, 15};

    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 35);
    sfText_setPosition(text, pos);
    sfText_setString(text, speech_loaders[id][style]);
    origin.x = (sfText_getGlobalBounds(text).width / 2);
    sfText_setOrigin(text, origin);
    return text;
}

static sfRectangleShape *speech_shape(sfVector2f pos)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfTexture *texture =
        sfTexture_createFromFile(textures_loaders[TX_DIALOG_MENU_BGR], NULL);
    sfVector2f origin = {0, 0};

    sfRectangleShape_setSize(shape, (sfVector2f) {800, 200});
    sfRectangleShape_setTexture(shape, texture, sfFalse);
    sfRectangleShape_setTextureRect(shape,
        (sfIntRect){.height = 122, .left = 139, .top = 12, .width = 106});
    sfRectangleShape_setPosition(shape, pos);
    origin = sfRectangleShape_getSize(shape);
    sfRectangleShape_setOrigin(shape,
        (sfVector2f){origin.x / 2, origin.y / 2});
    return shape;
}

void list_speech_append(list_speech_t *list, node_speech_t *node)
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

static void init_component_speech(node_speech_t *node, speech_id_t id)
{
    sfVector2f pos = {1920 / 2, 940 + 300};
    sfVector2f pt = {pos.x, pos.y - 70};

    node->title = speech_text((sfVector2f){pt.x - 300, pt.y}, id, SS_TITLE);
    node->paragraphe = speech_text((sfVector2f){pt.x, pt.y + 70}, id, SS_SP);
    node->shape = speech_shape(pos);
    node->clock = sfClock_create();
    node->time = speech_loaders_timer[id];
}

void new_speech(app_t *app, speech_id_t id)
{
    node_speech_t *node = malloc(sizeof(node_speech_t));

    if (!node )
        return;
    if (app->element->speech->first == NULL) {
        node->active = true;
        node->state = STS_APPARITION;
    } else {
        node->active = false;
        node->state = STS_NONE;
    }
    node->next = NULL;
    node->prev = NULL;
    init_component_speech(node, id);
    list_speech_append(app->element->speech, node);
    auto_call(app, id);
}
