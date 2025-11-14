#include "engine.h"

#include <stdlib.h>

void EntityInit(Entity* entity, float x, float y, Sprite* sprite) {
    entity->position = (Vector2){x, y};
    entity->velocity = (Vector2){0, 0};
    entity->sprite = *sprite;
}

void EntityUpdate(Entity* entity) {
    entity->position.x += entity->velocity.x;
    entity->position.y += entity->velocity.y;
    SpriteUpdate(&entity->sprite);
   
}

void EntityDraw(const Entity* entity) {
    SpriteDraw(&entity->sprite, (int)entity->position.x, (int)entity->position.y);
}

void EntitySetPosition(Entity* entity, float x, float y) {
    entity->position = (Vector2){x, y};
}
void EntitySetVelocity(Entity* entity, float vx, float vy) {
    entity->velocity = (Vector2){vx, vy};
}

void EntitySetCollider(Entity* entity, Collider collider) {
    entity->collider = collider;
}

Rectangle getRectangleFromCollider(const Entity* entity) {
    Rectangle rect;
    rect.x = entity->position.x + entity->collider.xoffset;
    rect.y = entity->position.y + entity->collider.yoffset;
    rect.width = entity->collider.width;
    rect.height = entity->collider.height;
    return rect;
}

void EntityUnload(Entity* entity) {
    SpriteUnload(&entity->sprite);
}

void TimerInit(Timer* timer, long duration, bool loop, bool autoStart, void (*callback)(void)) {
    timer->duration = duration;
    timer->loop = loop;
    timer->callback = callback;
    timer->active = autoStart;
    timer->currentTime = 0;
}

void TimerStart(Timer* timer) {
    timer->active = true;
    timer->currentTime = 0;
}

void TimerStop(Timer* timer) {
    timer->active = false;
}

void TimerUpdate(Timer* timer){
    if(!timer->active) return;
    timer->currentTime++;
    if(timer->currentTime>=timer->duration){
        if(timer->callback!=NULL){
            timer->callback();
        }
        if(timer->loop){
            timer->currentTime=0;
        }else{
            timer->active=false;
        }
    }
}