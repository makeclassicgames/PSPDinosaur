#include "resource.h"
#include "sprite.h"

#include <stdlib.h>

void SpriteInit(Sprite* sprite) {
    sprite->animations = NULL;
    sprite->currentAnimation = 0;
    sprite->animationCount = 0;
}

void SpriteUpdate(Sprite* sprite) {
    AnimationUpdate(&sprite->animations[sprite->currentAnimation]);
}

void SpriteDraw(const Sprite* sprite, int x, int y) {
    AnimationDraw(&sprite->animations[sprite->currentAnimation],x,y);
}

void SpriteUnload(Sprite* sprite) {
    for (int i = 0; i < sprite->animationCount; i++) {
        AnimationUnload(&sprite->animations[i]);
    }
    free(sprite->animations);
}



void SpriteSetSpriteAnimation(Sprite* sprite, int animationIndex){
    if(animationIndex<0 || animationIndex > sprite->animationCount){
            TraceLog(LOG_ERROR,"index Out Of Range");
    }

    sprite->currentAnimation=animationIndex;
}
// Animation Functions
void AnimationInit(Animation* animation, Texture2D* frames, int frameCount, int frameDelay
    , bool loop) {
  
}

void AnimationUpdate(Animation* animation) {
    animation->framesElapsed++;
    if(animation->framesElapsed>animation->frameDelay){
        animation->currentFrame++;
        if(animation->currentFrame>=animation->frameCount){
            animation->currentFrame = 0;
        }
        animation->framesElapsed = 0;
    }
    
}
void AnimationDraw(const Animation* animation, int x, int y) {
    DrawTexture(animation->frames[animation->currentFrame], x, y, WHITE);
} 

void AnimationUnload(Animation* animation) {
   free(animation->frames);
   free(animation);
}

Animation* AnimationBuilder(const int* frameResourceIds, int frameCount, int frameDelay, bool loop){
    Animation * animation = (Animation*)malloc(sizeof(Animation));
    Texture2D * frames = (Texture2D*)malloc(sizeof(Texture2D)*frameCount);
    for(size_t i = 0; i< frameCount;i++){
        frames[i] = *ResourceGetTexture(frameResourceIds[i]);
    } 
    animation->currentFrame = 0;
    animation->frameCount = frameCount;
    animation->frameDelay = frameDelay;
    animation->loop = loop;
    animation->frames= frames;
    animation->currentFrame = 0;
    animation->framesElapsed = 0;

    return animation;
}