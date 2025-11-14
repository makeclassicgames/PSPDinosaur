#ifndef ENGINE_H
#define ENGINE_H

#include <raylib.h>

#include "sprite.h"

#define SECONDS_TO_FRAME(sec) sec*60

typedef struct Collider{
    float xoffset;
    float yoffset;
    float width;
    float height;
} Collider;

typedef struct Entity{
    Vector2 position;
    Vector2 velocity;
    Sprite sprite;
    Collider collider; //Provisonal
} Entity;

typedef struct Timer{
    long currentTime;
    long duration;
    bool active;
    bool loop;
    void (*callback)(void);
} Timer;

void EntityInit(Entity* entity, float x, float y, Sprite* sprite);
void EntityUpdate(Entity* entity);
void EntityDraw(const Entity* entity);
void EntitySetPosition(Entity* entity, float x, float y);
void EntitySetVelocity(Entity* entity, float vx, float vy);
void EntityUnload(Entity* entity);
void EntitySetCollider(Entity* entity, Collider collider);
Rectangle getRectangleFromCollider(const Entity* entity);

//Timer Functions

void TimerInit(Timer* timer, long duration, bool loop, bool autoStart, void (*callback)(void));
void TimerStart(Timer* timer);
void TimerStop(Timer* timer);
void TimerUpdate(Timer* timer);


#endif // ENGINE_H