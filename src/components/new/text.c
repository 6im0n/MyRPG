/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** text set
*/

#include "components/components.h"
#include <stdbool.h>

void set_component_text(node_component_t *component,
char *string, sfColor color, int size)
{
    sfVector2f origin;
    sfFloatRect rect;

    if (!component && component->type != C_TYPES_TEXT)
        return;
    if (size != 0)
        sfText_setCharacterSize(component->object->text, size);
    sfText_setColor(component->object->text, color);
    sfText_setString(component->object->text, string);
    rect = sfText_getGlobalBounds(component->object->text);
    if (component->type != C_TYPES_BTN_TXT &&
        component->type != C_TYPES_SIGN)
        component->features.rendered_rect = rect;
    origin.x = rect.width / 2;
    origin.y = rect.height / 2;
    sfText_setOrigin(component->object->text, origin);
}

static void set_text_origin(node_component_t *component,
int middle)
{
    sfFloatRect rectT = sfText_getGlobalBounds(component->object->text);
    sfVector2f origin = {0, 0};

    switch (middle) {
        case 0:
            origin.x = rectT.width / 2;
            origin.y = rectT.height / 2;
            break;
        case 2:
            origin.y = rectT.height / 2;
            break;
        case 3:
            origin.x = rectT.width / 2;
            break;
        default:
            break;
    }
    sfText_setOrigin(component->object->text, origin);
}

void set_component_text_pos(node_component_t *component,
sfVector2f position, int middle)
{
    sfVector2f now_pos = sfText_getPosition(component->object->text);
    sfVector2f new_pos = {
        .x = now_pos.x + position.x,
        .y = now_pos.y + position.y,
    };

    if (!component && component->type != C_TYPES_TEXT)
        return;
    sfText_setPosition(component->object->text, new_pos);
    set_text_origin(component, middle);
}
