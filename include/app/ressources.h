/*
** EPITECH PROJECT, 2022
** RPG
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
ressources_t ressources_load(app_t *app);

/**
 * @brief Destroy loaded ressources
 * @param ressources Ressources to unload
 */
void ressources_unload(ressources_t *ressources);

/**
 * @brief Import textures
 */
sfTexture **ressources_import_textures(app_t *app);

/**
 * @brief Destroy given textures
 * @param textures Textures to destroy
 */
void ressources_destroy_textures(sfTexture **textures);

/**
 * @brief Import sounds
 */
sfSoundBuffer**ressources_import_sounds(app_t *app);

/**
 * @brief Destroy given sounds
 * @param sounds Sounds to destroy
 */
void ressources_destroy_sounds(sfSoundBuffer**sounds);

/**
 * @brief Import fonts
 */
sfFont **ressources_import_fonts(app_t *app);

/**
 * @brief Destroy given fonts
 * @param fonts Fonts to destroy
 */
void ressources_destroy_fonts(sfFont **fonts);

#endif /* !APP_RESSOURCES_H_ */
