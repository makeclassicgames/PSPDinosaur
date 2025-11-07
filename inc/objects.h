#ifndef OBJECTS_H
#define OBJECTS_H

#include "engine.h"

#include <raylib.h>

enum ObjectType{
    CACTUS0,
    CACTUS1,
    CACTUS2,
    PETRODACTIL
};

typedef struct Object{
    Entity entity;
    enum ObjectType objectType;
} Object;

void ObjectInit(Object* object, float x, float y, enum ObjectType type);
void ObjectUpdate(Object* object);
void ObjectDraw(const Object* object);
#endif // OBJECTS_H