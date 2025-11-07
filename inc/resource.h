#ifndef RESOURCE_H
#define RESOURCE_H

#include <raylib.h>

typedef struct TextureResource{
    Texture2D Texture;
}TextureResource;

#define RSOURCE_DUCK_WALK_0 0
#define RSOURCE_DUCK_WALK_1 1
#define RSOURCE_DUCK_WALK_2 2
#define RSOURCE_DUCK_WALK_3 3
#define RSOURCE_DUCK_DOWN_0 4
#define RSOURCE_DUCK_DOWN_1 5
#define RSOURCE_DUCK_DOWN_2 6
#define RSOURCE_DUCK_DOWN_3 7
#define RESOURCE_CACTUS0 8
#define RESOURCE_CACTUS1 9
#define RESOURCE_CACTUS2 10
#define RESOURCE_PTERODACTYL0 11
#define RESOURCE_PTERODACTYL1 12

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