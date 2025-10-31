#include <stdlib.h>
#include "resource.h"

#define MAX_TEXTURES 8



ResourceManager resourceManager;

const char* textureResources[] = {
    "host0:/dinosaur/resources/JamonAndar0.png",
    "host0:/dinosaur/resources/JamonAndar1.png",
    "host0:/dinosaur/resources/JamonAndar2.png",
    "host0:/dinosaur/resources/JamonAndar3.png",
    "host0:/dinosaur/resources/JamonAgachada0.png",
    "host0:/dinosaur/resources/JamonAgachada1.png",
    "host0:/dinosaur/resources/JamonAgachada2.png",
    "host0:/dinosaur/resources/JamonAgachada3.png"

};

SoundResource soundResources[] = {
    
};

void ResourceManagerInit() {
    resourceManager.textureCount = MAX_TEXTURES;
    resourceManager.textures = (TextureResource*)malloc(sizeof(TextureResource) * resourceManager.textureCount);
    
    for (int i = 0; i < resourceManager.textureCount; i++) {
        resourceManager.textures[i].Texture = LoadTexture(textureResources[i]);
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
