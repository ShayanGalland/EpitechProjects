#ifndef _SPRITES_H
#define _SPRITES_H

#include "SFML/Graphics.h"

sfTexture* create_texture(const char* texture_path);
sfSprite* create_sprite(sfTexture* texture);


#endif