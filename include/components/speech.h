/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** speech
*/

#ifndef SPEECH_H_
    #define SPEECH_H_

    #include "types/type.h"

/**
* @brief Create a new speech
* @param app
* @param id
*/

void new_speech(app_t *app, speech_id_t id);

/**
* @brief Render the speech
* @param app
*/
void speech_render(app_t *app);;

/**
 * @brief Call a speech
 *
 * @param app
 * @param id
 */
void auto_call(app_t *app, speech_id_t id);

/**
 * @brief Remove a speech from the list
 *
 * @param list
 * @param node
 */
void list_removes(list_speech_t *list, node_speech_t *node);

#endif /* !SPEECH_H_ */
