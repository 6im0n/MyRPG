/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** init
*/

#include "components/components.h"

static void init_text(parsing_t *element)
{
    element->radius = 0;
    element->text = NULL;
    element->text_pos = (sfVector2f){-1, -1};
    element->text_pos_type = -1;
    element->text_size = -1;
}

void parsing_init(parsing_t *elements)
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
    elements->function.next_to = NEXT_TO_LEN;
    elements->animation.rect = (sfIntRect){-1, -1, -1, -1};
    elements->animation.index = -1;
    elements->animation.max = -1;
    elements->animation.speed = -1;
    init_text(elements);
}
