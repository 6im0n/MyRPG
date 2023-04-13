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
     * @brief Get component onkeyrelease handler
     */
    #define COMPONENT_ON_KEYRELEASE(component) (component->events.onkeyrelease)

    /**
     * @brief Get component onkeypress handler
     */
    #define COMPONENT_ON_DISABLED(component) (component->events.ondisabled)

    /**
     * @brief Get component onkeypress handler
     */
    #define COMPONENT_NEXT_TO(component) (component->events.next_to)

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
 * @brief Function if a key is released
 * @param component Component to state
 * @param event Event
 * @param app App object
 */
void component_onkeyrelease(node_component_t *component,event_t *event,
app_t *app);

/**
 * @brief Function if component is not hover
 * @param component Component to state
 * @param event Event
 * @param app App object
 */
void component_ondisabled(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Function if component near of the player
 * @param component Component to state
 * @param event Event
 * @param app App object
 */
void component_next_to(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Set state to the component
 * @param component Component to state
 * @param event Event
 */
void component_set_state_from_event(node_component_t *component,
event_t *event, app_t *app);

/**
 * @brief Move the player
 * @param app App
 */
void move_player(app_t *app);

/**
 * @brief Find if components is near of the player
 * @param component component
 * @param app app
 * @param event event
 */
void component_near(list_components_t *component,
app_t *app, event_t *event);

/**
 * @brief Detect if component is near of the player
 * @param component component
 * @param app app
 * @return true
 * @return false
 */
bool component_next_to_player(node_component_t *component,
app_t *app);

#endif /* !COMPONENTS_EVENTS_H_ */
