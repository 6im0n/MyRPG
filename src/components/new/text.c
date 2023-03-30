/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** text set
*/

#include "components/components.h"

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
    component->features.rendered_rect = rect;
    origin.x = rect.width / 2;
    origin.y = rect.height / 2;
    sfText_setOrigin(component->object->text, origin);
}
