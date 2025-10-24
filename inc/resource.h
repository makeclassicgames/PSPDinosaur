#ifndef RESOURCE_H
#define RESOURCE_H

#include <raylib.h>

typedef struct TextureResource{
    Texture2D Texture;
}TextureResource;

#define RSOURCE_DUCK_WALK_0 0
#define RSOURCE_DUCK_WALK_1 1

typedef struct SoundResource{
    Sound Sound;
}SoundResource;

typedef struct ResourceManager{
    TextureResource* textures;
    int textureCount;
    SoundResource* sounds;
    int soundCount;
}ResourceManager;

void ResourceManagerInit();
Texture2D* ResourceGetTexture(int index);
Sound* ResourceGetSound(int index);
void ResourceManagerUnload();

#endif // RESOURCE_H