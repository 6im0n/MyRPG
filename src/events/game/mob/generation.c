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
        color = sfImage_getPixel(app->element->player->collisions, x, y + 50);
        if ((color.a == 0))
            add_new_mob(app, app->element->ressources, (sfVector2f){ x, y });
    }
}

void generation_mob_next_to(node_component_t *component,
event_t *event, app_t *app)
{
    bool on_player = sfFloatRect_intersects(
        &component->features.rendered_rect,
        &app->element->player->character->frect, NULL);

    (void) event;
    if (on_player)
        return;
    if (app->element->mobs->len < 3)
        generation_random_mob(app, component->features.rendered_rect);
    sfRectangleShape_setOutlineColor(component->object->rectangle, sfBlack);
    component->features.select = true;
}

void generation_mob_ondisabled(node_component_t *component,
event_t *event, app_t *app)
{
    (void) event;
    if (component->features.select == false)
        return;
    (void)app;
    if (!ST_IS_NEAR(component)) {
        list_mob_delete(app);
        component->features.select = false;
    }
}
