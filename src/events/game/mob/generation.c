/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** generation
*/

#include "lib/output.h"
#include "types/type.h"
#include "components/components.h"
#include "components/mobs.h"
#include <stdlib.h>

void generation_mob_next_to(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;
    if (app->element->mobs->len > 0 && !ST_IS_HOVER(component)) {
        my_printf("Despawn\n");
        component->features.select = false;
    }
}

static void generation_random_mob(app_t *app, sfFloatRect rect)
{
    sfVector2f pos_random = { rect.left, rect.top };
    int x = 0;
    int y = 0;
    int nbr = rand() % ((int)rect.width / 10);
    sfColor color = {0, 0, 0, 255};

    for (int i = 0; i < nbr; i++) {
        x = (rand() % (int)rect.width) + (int)pos_random.x;
        y = (rand() % (int)rect.height) + (int)pos_random.y;
        color = sfImage_getPixel(app->element->player->collisions, x, y);
        if ((color.r == sfBlack.r && color.g == sfBlack.g
            && color.b == sfBlack.b  && color.a == sfBlack.a))
            add_new_mob(app, app->element->ressources, (sfVector2f){x, y});
    }
}

void generation_mob_on(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    (void) app;
    (void) component;

    if (component->features.select == false) {
        my_printf("Spawn mob :D\n");
        component->features.select = true;
        generation_random_mob(app, component->features.rendered_rect);
    }
}
