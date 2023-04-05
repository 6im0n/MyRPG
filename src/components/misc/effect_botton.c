/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** render
*/


#include "components/components.h"

static sfIntRect effect_select_size(sfIntRect defaul, component_size_t size)
{
    switch (size) {
        case C_SIZE_BIG:
            defaul.left = (defaul.left + 96);
            break;
        case C_SIZE_SMALL:
            defaul.left = (defaul.left + 32);
            break;
        default:
            break;
    }
    return defaul;
}

static void is_pressed(node_component_t *component,
sfIntRect defaul)
{
    sfIntRect clicked = effect_select_size(defaul, component->features.size);

    if (ST_IS_PRESSED(component))
        sfRectangleShape_setTextureRect(component->object->rectangle, clicked);
    else
        sfRectangleShape_setTextureRect(component->object->rectangle, defaul);
}

static void is_selector(node_component_t *component, sfIntRect defaul)
{
    sfIntRect select = {defaul.left, defaul.top - 32,
        defaul.width, defaul.height};

    if (component->features.select == true)
        sfRectangleShape_setTextureRect(component->object->rectangle, select);
    else
        sfRectangleShape_setTextureRect(component->object->rectangle, defaul);
}

void render_button_effect(app_t *app, node_component_t *component)
{
    sfIntRect defaul = component->features.texture_rect;

    if (ST_IS_HOVER(component)) {
        is_pressed(component, defaul);
        sfRectangleShape_setScale(component->object->rectangle,
        (sfVector2f){0.98, 0.98});
    } else {
        sfRectangleShape_setScale(component->object->rectangle,
        (sfVector2f){1, 1});
        component->state = ST_SET_HOVER(component, false);
        sfRectangleShape_setTextureRect(component->object->rectangle,
        defaul);
    }
    if (component->id == ID_SELECTOR)
        is_selector(component, defaul);
    sfRenderWindow_drawRectangleShape(app->window,
    component->object->rectangle, NULL);
}
