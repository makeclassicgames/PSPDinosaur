#include "engine.h"

void EntityInit(Entity* entity, float x, float y, Sprite* sprite) {
    entity->position = (Vector2){x, y};
    entity->velocity = (Vector2){0, 0};
    entity->sprite = *sprite;
    entity->collider = (Rectangle){x, y, sprite->animations[0].frames[0].width, sprite->animations[0].frames[0].height};
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

void EntityUnload(Entity* entity) {
    SpriteUnload(&entity->sprite);
}