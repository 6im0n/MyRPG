/*
** EPITECH PROJECT, 2023
** my_paint
** File description:
** events
*/

#ifndef COMPONENTS_EVENTS_H_
    #define COMPONENTS_EVENTS_H_

    /**
     * @brief Get component onclick handler
     */
    #define COMPONENT_ON_CLICK(component) (component->events.onclick)

        /**
     * @brief Get component onhover handler
     */
    #define COMPONENT_ON_HOVER(component) (component->events.onhover)

    /**
     * @brief Get component onmove handler
     */
    #define COMPONENT_ON_MOVE(component) (component->events.onmove)

    /**
     * @brief Get component onnonclick handler
     */
    #define COMPONENT_ON_NONCLICK(component) (component->events.onnonclick)

    /**
     * @brief Get component onkeypress handler
     */
    #define COMPONENT_ON_KEYPRESS(component) (component->events.onkeypress)

    /**
     * @brief Get component onkeypress handler
     */
    #define COMPONENT_ON_DISABLED(component) (component->events.ondisabled)

/**
 * @brief Function if component is clicked
 * @param component Component to state
 * @param event Event
 * @param app App object
 */
void component_onclick(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Function if component is hover
 * @param component Component to state
 * @param event Event
 * @param app App object
 */
void component_onhover(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Function if component is moved
 * @param component Component to state
 * @param event Event
 * @param app App object
 */
void component_onmove(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Function if another component of current is clicked
 * @param component Component to state
 * @param event Event
 * @param app App object
 */
void component_onnonclick(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Function if a key is pressed
 * @param component Component to state
 * @param event Event
 * @param app App object
 */
void component_onkeypress(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Function if component is not hover
 * @param component Component to state
 * @param event Event
 * @param app App object
 */
void component_ondisabled(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Set state to the component
 * @param component Component to state
 * @param event Event
 */
void component_set_state_from_event(node_component_t *component,
event_t *event);

#endif /* !COMPONENTS_EVENTS_H_ */
