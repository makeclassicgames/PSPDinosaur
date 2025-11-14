#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "resource.h"

#define MAX_TEXTURES 13



ResourceManager resourceManager;

const char* textureResources[] = {
    "resources/JamonAndar0.png",
    "resources/JamonAndar1.png",
    "resources/JamonAndar2.png",
    "resources/JamonAndar3.png",
    "resources/JamonAgachada0.png",
    "resources/JamonAgachada1.png",
    "resources/JamonAgachada2.png",
    "resources/JamonAgachada3.png",
    "resources/pino1.png",
    "resources/cactus1.png",
    "resources/cactus2.png",
    "resources/petrodactil0.png",
    "resources/petrodactil1.png"
};

SoundResource soundResources[] = {
    
};

void ResourceManagerInit() {
    char buffer[256];
    
    resourceManager.textureCount = MAX_TEXTURES;
    resourceManager.textures = (TextureResource*)malloc(sizeof(TextureResource) * resourceManager.textureCount);
    
    for (int i = 0; i < resourceManager.textureCount; i++) {
        sprintf(buffer, "%s/%s", GetWorkingDirectory(), textureResources[i]);
        resourceManager.textures[i].Texture = LoadTexture(buffer);
    }
    
    resourceManager.soundCount = 0;
    resourceManager.sounds = NULL;
}

Texture2D* ResourceGetTexture(int index) {
    if (index < 0 || index >= resourceManager.textureCount) {
        return NULL;
    }
    return &resourceManager.textures[index].Texture;
}

Sound* ResourceGetSound(int index) {
    if (index < 0 || index >= resourceManager.soundCount) {
        return NULL;
    }
    return &resourceManager.sounds[index].Sound;
}

void ResourceManagerUnload() {
    for (int i = 0; i < resourceManager.textureCount; i++) {
        UnloadTexture(resourceManager.textures[i].Texture);
    }
    free(resourceManager.textures);

    
    free(resourceManager.sounds);
}
