#ifndef SPRITE_H
#define SPRITE_H

#include <raylib.h>

typedef struct Sprite{
    Animation* animations;
    int currentAnimation;
    int animationCount;
}Sprite;

typedef struct Animation{
    int frameCount;
    int frameDelay;
    int framesElapsed;
    bool loop;
    Texture2D* frames;
    int currentFrame;
}Animation;


void SpriteInit(Sprite* sprite, const char* texturePath);
void SpriteUpdate(Sprite* sprite);
void SpriteDraw(const Sprite* sprite, int x, int y);
void SpriteUnload(Sprite* sprite);
void SetSpriteAnimation(Sprite* sprite, int animationIndex);

//Animation Functions
void AnimationInit(Animation* animation, Texture2D* frames, int frameCount, int frameDelay
    , bool loop);
void AnimationUpdate(Animation* animation);
void AnimationDraw(const Animation* animation, int x, int y);
void AnimationUnload(Animation* animation);
void SetAnimationFrame(Animation* animation, int frameIndex);


#endif