/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** renderer
*/

#include "types/type.h"
#include <SFML/Graphics.h>

renderer_objects_t renderer_objects_create(sfRenderWindow *window)
{
    sfSprite *sprite = sfSprite_create();
    sfText *text = sfText_create();
    sfCircleShape *circle = sfCircleShape_create();
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfView *view = sfView_create();
    renderer_objects_t objects = {  window, view, sprite, text,
                                    circle, rectangle  };

    return (objects);
}

void renderer_objects_destroy(renderer_objects_t *objects)
{
    if (objects) {
        sfSprite_destroy(objects->sprite);
        sfText_destroy(objects->text);
        sfCircleShape_destroy(objects->circle);
        sfRectangleShape_destroy(objects->rectangle);
        sfView_destroy(objects->view);
    }
}
