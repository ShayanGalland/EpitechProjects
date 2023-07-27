#include "sprites.h"

sfTexture *create_texture(const char *texture_path)
{
    return sfTexture_createFromFile(texture_path, NULL);
}
sfSprite *create_sprite(sfTexture *texture)
{
    sfSprite *mySprite = sfSprite_create();
    sfSprite_setTexture(mySprite, texture, 0);
    return mySprite;
}