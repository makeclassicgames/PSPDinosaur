#ifndef ENGINE_H
#define ENGINE_H

#include <raylib.h>

#include "sprite.h"

typedef struct Entity{
    Vector2 position;
    Vector2 velocity;
    Sprite sprite;
    Rectangle collider; //Provisonal
} Entity;

void EntityInit(Entity* entity, float x, float y, Sprite* sprite);
void EntityUpdate(Entity* entity);
void EntityDraw(const Entity* entity);
void EntitySetPosition(Entity* entity, float x, float y);
void EntitySetVelocity(Entity* entity, float vx, float vy);
void EntityUnload(Entity* entity);


#endif // ENGINE_H