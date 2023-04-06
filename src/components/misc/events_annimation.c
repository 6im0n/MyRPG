/*
** EPITECH PROJECT, 2023
** RPG [WSL : Ubuntu]
** File description:
** Annimation
*/


#include "components/components.h"
#include "types/renderer.h"

static void draw_render_annimation(node_component_t *component, sfIntRect rect)
{
    switch (component->type) {
        case C_TYPES_SIGN:
            sfRectangleShape_setTextureRect(component->object->rectangle,
            rect);
            break;
        default:
            break;
    }
}

static void annimation_edit(node_component_t *component)
{
    sfIntRect rect = component->features.texture_rect;
    sfIntRect rect_a = component->annimation.rect;

    if (component->annimation.index > component->annimation.max)
        component->annimation.index = 0;
    rect_a.height *= component->annimation.index;
    rect_a.top *= component->annimation.index;
    rect_a.left *= component->annimation.index;
    rect_a.width *= component->annimation.index;
    rect.height += rect_a.height;
    rect.top += rect_a.top;
    rect.left += rect_a.left;
    rect.width += rect_a.width;
    draw_render_annimation(component, rect);
    component->annimation.index++;
}

static void render_annimation(app_t *app,
node_component_t *component)
{
    sfTime time = sfClock_getElapsedTime(component->object->clock);
    float seconds = time.microseconds / 1000000.0;

    (void) app;
    if (seconds > component->annimation.speed) {
        annimation_edit(component);
        sfClock_restart(component->object->clock);
    }
}

void component_render_annimation(app_t *app,
node_component_t *component)
{
    if (!(component->annimation.speed > 0))
        return;
    switch (component->type) {
        case C_TYPES_SIGN:
            render_annimation(app, component);
            break;
        default:
            break;
    }
}
