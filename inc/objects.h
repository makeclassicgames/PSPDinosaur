#ifndef OBJECTS_H
#define OBJECTS_H

#include "engine.h"

#include <raylib.h>

#define MAX_OBJECTS 10

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

typedef struct ObjectNode{
    int objectID;
    Object object;

} ObjectNode;

typedef struct ObjectList{
   ObjectNode* objects;
   int count;
} ObjectList;



void ObjectInit(Object* object, float x, float y, enum ObjectType type);
void ObjectUpdate(Object* object);
void ObjectDraw(const Object* object);

void ObjectListInit(ObjectList* list);
void ObjectListAdd(ObjectList* list, Object object);
void ObjectListGet(ObjectList* list, int objectId, Object* outObject);
void ObjectListRemove(ObjectList* list, int objectId);
ObjectNode* ObjectListToArray(ObjectList* list, int* outCount);

#endif // OBJECTS_H