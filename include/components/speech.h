/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** speech
*/

#ifndef SPEECH_H_
    #define SPEECH_H_

    #include "types/type.h"

void new_speech(app_t *app, speech_id_t id);

void speech_render(app_t *app);;

void auto_call(app_t *app, speech_id_t id);

void list_removes(list_speech_t *list, node_speech_t *node);

#endif /* !SPEECH_H_ */
