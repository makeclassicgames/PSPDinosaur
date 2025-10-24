#ifndef SPRITE_H
#define SPRITE_H

#include <raylib.h>

typedef struct Animation{
    int frameCount;
    int frameDelay;
    int framesElapsed;
    bool loop;
    Texture2D* frames;
    int currentFrame;
}Animation;

typedef struct Sprite{
    Animation* animations;
    int currentAnimation;
    int animationCount;
}Sprite;



void SpriteInit(Sprite* sprite);
void SpriteUpdate(Sprite* sprite);
void SpriteDraw(const Sprite* sprite, int x, int y);
void SpriteUnload(Sprite* sprite);
void SpriteSetSpriteAnimation(Sprite* sprite, int animationIndex);

//Animation Functions
void AnimationUpdate(Animation* animation);
void AnimationDraw(const Animation* animation, int x, int y);
void AnimationUnload(Animation* animation);
void SetAnimationFrame(Animation* animation, int frameIndex);
Animation* AnimationBuilder(const int* frameResourceIds, int frameCount, int frameDelay, bool loop);

#endif