/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** parsing
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "lib/str.h"
#include "utils/file.h"
#include "types/type.h"
#include "types/list.h"
#include "components/new.h"
#include "components/components.h"
#include "event/start_menu/bouton.h"
#include "event/functions.h"
#include "parsing/utils.h"
#include "types/node.h"

static void parsing_init(parsing_t *elements)
{
    elements->types[0] = '\0';
    elements->position = (sfVector2f){-1, -1};
    elements->size = (sfVector2f){-1, -1};
    elements->rect = (sfIntRect){-1, -1, -1, -1};
    elements->type = C_TYPES_LEN;
    elements->c_size = C_SIZE_LEN;
    elements->style = (component_styles){TX_LEN, SD_LEN, FT_LEN};
    elements->function.clicked = CLICKED_LEN;
    elements->function.hover = HOVER_LEN;
    elements->function.disabled = DISABLED_LEN;
    elements->function.moved = MOVED_LEN;
    elements->function.nonclicked = NONCLICKED_LEN;
    elements->function.pressed = KEYPRESSED_LEN;
    elements->function.released = KEYRELEASED_LEN;
    elements->animation.rect = (sfIntRect){-1, -1, -1, -1};
    elements->animation.index = -1;
    elements->animation.max = -1;
    elements->animation.speed = -1;
}

void parsing_set_functions(node_component_t *obj, parsing_t *element)
{
    if (element->function.clicked != CLICKED_LEN)
        obj->events.onclick = clicked_event[element->function.clicked];
    if (element->function.hover != HOVER_LEN)
        obj->events.onhover = hover_event[element->function.hover];
    if (element->function.disabled != DISABLED_LEN)
        obj->events.ondisabled = disable_event[element->function.disabled];
    if (element->function.moved != MOVED_LEN)
        obj->events.onhover = moved_event[element->function.moved];
    if (element->function.pressed != KEYPRESSED_LEN)
        obj->events.onkeypress = pressed_event[element->function.pressed];
    if (element->function.released != KEYRELEASED_LEN)
        obj->events.onkeyrelease = released_event[element->function.released];
}

static void parsing_append(parsing_t *element, ressources_t ressources,
                            list_components_t *list)
{
    node_component_t *obj = node_component_init();
    sfVector2f size = element->size;
    sfVector2f position = element->position;
    sfFloatRect rect = {.height = size.y, .left = (position.x - (size.x / 2)),
                .top = (position.y - (size.y / 2)), .width = size.x};

    new_component_set(obj, rect, element->type, element->style);
    new_component_type(ressources, obj, position);
    new_component_size(obj, size, element->rect, element->c_size);
    if (element->animation.index != -1)
        new_component_annimation(obj, element->animation.rect,
        element->animation.index, element->animation.max);
    if (element->animation.speed != -1) {
        obj->annimation.max_speed = element->animation.speed;
        obj->annimation.speed = element->animation.speed;
    }
    parsing_set_functions(obj, element);
    list_component_append(list, obj);
}

static void extend_function(parsing_t *element, int *index,
                            char *file)
{
    char end[4] = { '\0', '\0', '\0', '\0' };
    int type_index = 0;

    while (my_strcmp(end, "###") != 0) {
        if (file[*index] == ':') {
            manage_number(file, element, index);
            type_index = 0;
            clean_char(element->types, 15);
        } else {
            element->types[type_index] = file[*index];
            type_index++;
        }
        end[0] = file[*index];
        end[1] = file[*index + 1];
        end[2] = file[*index + 2];
        *index += 1;
    }
}

void parsing_buttons(app_t *app, ressources_t ressources,
                    list_components_t *list, char *filepath)
{
    parsing_t element;
    char *file = file_load(filepath);
    int index = 0;

    (void)app;
    parsing_init(&element);
    clean_char(element.types, 15);
    while (file[index] != '\0') {
        extend_function(&element, &index, file);
        index += 3;
        parsing_append(&element, ressources, list);
        parsing_init(&element);
    }
    free(file);
}
