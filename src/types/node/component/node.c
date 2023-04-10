/*
** EPITECH PROJECT, 2023
** B-MUL-200-NAN-2-1-myrpg-thomas.quintin
** File description:
** node
*/

#include "components/components.h"

node_component_t *node_component_init(void)
{
    node_component_t *tmp = malloc(sizeof(node_component_t));
    sfIntRect rect = {0, 0, 0, 0};

    if (!tmp)
        return 0;
    tmp->annimation = (component_annimation_t){rect, 0, 0, 0, 0};
    tmp->state = 0;
    tmp->id = ID_UNDEFINED;
    tmp->type = C_UNDEFINED;
    tmp->object = NULL;
    tmp->features.rendered_rect = (sfFloatRect){0, 0, 0, 0};
    tmp->features.texture_rect = (sfIntRect){0, 0, 0, 0};
    tmp->features.styles = (component_styles){TX_LEN, SD_LEN, FT_LEN};
    tmp->features.select = false;
    tmp->events =
    (component_events_t){NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}
