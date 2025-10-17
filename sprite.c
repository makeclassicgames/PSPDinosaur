#include "sprite.h"

void SpriteInit(Sprite* sprite, const char* texturePath) {
    sprite->texture = LoadTexture(texturePath);
}

void SpriteUpdate(Sprite* sprite) {
    // Update sprite logic here (e.g., animations) Ya veremos
}

void SpriteDraw(const Sprite* sprite, int x, int y) {
    AnimationDraw(&sprite->animations[sprite->currentAnimation], x, y);
}

void SpriteUnload(Sprite* sprite) {
    for (int i = 0; i < sprite->animationCount; i++) {
        AnimationUnload(&sprite->animations[i]);
    }
}

// Animation Functions
void AnimationInit(Animation* animation, Texture2D* frames, int frameCount, int frameDelay
    , bool loop) {
    animation->frames = frames;
    animation->frameCount = frameCount;
    animation->frameDelay = frameDelay;
    
    animation->loop = loop;
    animation->currentFrame = 0;
    animation->framesElapsed = 0;
}

void AnimationUpdate(Animation* animation) {
    // Update animation logic here (e.g., frame switching) Ya veremos

    //Recalculate next Frame using frameDelay
    
}
void AnimationDraw(const Animation* animation, int x, int y) {
    DrawTexture(animation->frames[animation->currentFrame], x, y, WHITE);
} 

void AnimationUnload(Animation* animation) {
    for (int i = 0; i < animation->frameCount; i++) {
        UnloadTexture(animation->frames[i]);
    }
}