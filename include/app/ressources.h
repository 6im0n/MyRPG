/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** ressources
*/

#ifndef APP_RESSOURCES_H_
    #define APP_RESSOURCES_H_
    #include <SFML/Graphics.h>
    #include "types/type.h"
    #include <SFML/Audio.h>

/**
 * @brief Load ressources in memory
 */
ressources_t ressources_load(void);

/**
 * @brief Destroy loaded ressources
 * @param ressources Ressources to unload
 */
void ressources_unload(ressources_t *ressources);

/**
 * @brief Import textures
 */
sfTexture **ressources_import_textures(void);

/**
 * @brief Destroy given textures
 * @param textures Textures to destroy
 */
void ressources_destroy_textures(sfTexture **textures);

/**
 * @brief Import sounds
 */
sfSoundBuffer**ressources_import_sounds(void);

/**
 * @brief Destroy given sounds
 * @param sounds Sounds to destroy
 */
void ressources_destroy_sounds(sfSoundBuffer**sounds);

#endif /* !APP_RESSOURCES_H_ */
