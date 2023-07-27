/*
** EPITECH PROJECT, 2021
** Shayan GALLAND
** File description:
** project in c
*/
#include "function.h"

back_t *back_stat()
{
    back_t *back_gr = malloc(sizeof(back_t));
    char *textures[3] = { "assets/back1.jpg", "assets/back2.png", "assets/back3.png" };
    back_gr->tex_un = sfTexture_createFromFile(textures[0], NULL);
    back_gr->tex_deux = sfTexture_createFromFile(textures[0], NULL);
    back_gr->tex_trois = sfTexture_createFromFile(textures[0], NULL);
    back_gr->tex_quatre = sfTexture_createFromFile(textures[1], NULL);
    back_gr->tex_cinq = sfTexture_createFromFile(textures[1], NULL);
    back_gr->tex_six = sfTexture_createFromFile(textures[1], NULL);
    back_gr->tex_sept = sfTexture_createFromFile(textures[2], NULL);
    back_gr->tex_huit = sfTexture_createFromFile(textures[2], NULL);
    back_gr->tex_neuf = sfTexture_createFromFile(textures[2], NULL);
    back_gr->sprite_un = create_sprite(back_gr->tex_un);
    back_gr->sprite_deux = create_sprite(back_gr->tex_deux);
    back_gr->sprite_trois = create_sprite(back_gr->tex_trois);
    back_gr->sprite_quatre = create_sprite(back_gr->tex_quatre);
    back_gr->sprite_cinq = create_sprite(back_gr->tex_cinq);
    back_gr->sprite_six = create_sprite(back_gr->tex_six);
    back_gr->sprite_sept = create_sprite(back_gr->tex_sept);
    back_gr->sprite_huit = create_sprite(back_gr->tex_huit);
    back_gr->sprite_neuf = create_sprite(back_gr->tex_neuf);
    return back_gr;
}