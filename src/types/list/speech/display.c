/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** display
*/

#include "components/speech.h"

static void annimation_set(list_speech_t *list)
{
    sfVector2f pos = sfRectangleShape_getPosition(list->first->shape);
    sfVector2f title = sfText_getPosition(list->first->title);
    sfVector2f para = sfText_getPosition(list->first->paragraphe);

    if (list->first->state == STS_APPARITION && pos.y > 920) {
        pos.y -= 2;
        title.y -= 2;
        para.y -= 2;
        sfRectangleShape_setPosition(list->first->shape, pos);
        sfText_setPosition(list->first->title, title);
        sfText_setPosition(list->first->paragraphe, para);
    }
    if (list->first->state == STS_DEPOP && pos.y < 1240) {
        pos.y += 2;
        title.y += 2;
        para.y += 2;
        sfRectangleShape_setPosition(list->first->shape, pos);
        sfText_setPosition(list->first->title, title);
        sfText_setPosition(list->first->paragraphe, para);
    }
}

static void annimation_speech(list_speech_t *list)
{
    sfTime time = sfClock_getElapsedTime(list->first->clock);

    annimation_set(list);
    if (sfTime_asSeconds(time) > (list->first->time - 2))
        list->first->state = STS_DEPOP;
    if (sfTime_asSeconds(time) > list->first->time) {
        list_removes(list, list->first);
        if (!list->first)
            return;
        sfClock_restart(list->first->clock);
        list->first->active = true;
        list->first->state = STS_APPARITION;
    }
}

void speech_render(app_t *app)
{
    node_speech_t *tmp = app->element->speech->first;

    if (!tmp)
        return;
    if (tmp->active == true) {
        sfRenderWindow_drawRectangleShape(app->window, tmp->shape, NULL);
        sfRenderWindow_drawText(app->window, tmp->title, NULL);
        sfRenderWindow_drawText(app->window, tmp->paragraphe, NULL);
    }
    annimation_speech(app->element->speech);
}
