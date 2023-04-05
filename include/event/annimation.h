/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouton
*/

#ifndef EVENT_ANNIMATION_H_
    #define EVENT_ANNIMATION_H_

    #include "components/components.h"

void event_active_annimation(node_component_t *component,
event_t *event, app_t *app);

void event_disabled_annimation(node_component_t *component,
event_t *event, app_t *app);

void event_pause_annimation(node_component_t *component,
event_t *event, app_t *app);

#endif /* !EVENT_ANNIMATION_H_ */
