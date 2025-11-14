#include <stdlib.h>
#include "objects.h"
#include "resource.h"

void loadObjectSprite0(Object* object);
void loadObjectSprite1(Object* object);
void loadObjectSprite2(Object* object);
void loadObjectSprite3(Object* object);

void ObjectInit(Object* object, float x, float y, enum ObjectType type){
    TraceLog(LOG_INFO,"Initializing Object of Type %d",type);
    object->objectType = type;
    SpriteInit(&object->entity.sprite);
    TraceLog(LOG_INFO,"Loading Sprite for Object Type %d",object->objectType);
    switch (object->objectType)
    {
    case CACTUS0:
        loadObjectSprite0(object);
        break;
    case CACTUS1:
        loadObjectSprite1(object);
        break;
    case CACTUS2:
        loadObjectSprite2(object);
        break;
    case PETRODACTIL:
        loadObjectSprite3(object);
        break;

    }
    EntityInit(&object->entity, x, y, &object->entity.sprite);

}

void loadObjectSprite0(Object* object){
    TraceLog(LOG_INFO,"Loading Sprite 0");
    Animation * animation = AnimationBuilder((const int[]){RESOURCE_CACTUS0}, 1, 5, true);
    object->entity.sprite.animations = animation;
    object->entity.sprite.animationCount = 1;
    TraceLog(LOG_INFO,"Sprite 0 Loaded");
}

void loadObjectSprite1(Object* object){
    TraceLog(LOG_INFO,"Loading Sprite 1");
    Animation * animation = AnimationBuilder((const int[]){RESOURCE_CACTUS1}, 1, 5, true);
    object->entity.sprite.animations = animation;
    object->entity.sprite.animationCount = 1;
}

void loadObjectSprite2(Object* object){
    TraceLog(LOG_INFO,"Loading Sprite 2");
    Animation * animation = AnimationBuilder((const int[]){RESOURCE_CACTUS2}, 1, 5, true);
    object->entity.sprite.animations = animation;
    object->entity.sprite.animationCount = 1;
}

void loadObjectSprite3(Object* object){
    TraceLog(LOG_INFO,"Loading Sprite 3");
    Animation * animation = AnimationBuilder((const int[]){RESOURCE_PTERODACTYL0, RESOURCE_PTERODACTYL1}, 2, 5, true);
    object->entity.sprite.animations= animation;
    object->entity.sprite.animationCount = 1;
}

void ObjectUpdate(Object* object){
    EntityUpdate(&object->entity);
}
void ObjectDraw(const Object* object){
    EntityDraw(&object->entity);
}

void ObjectListInit(ObjectList* list){
    list->objects = (ObjectNode*)malloc(sizeof(ObjectNode) * MAX_OBJECTS);
    list->count = 0;
}

void ObjectListAdd(ObjectList* list, Object object){
    if(list->count>=MAX_OBJECTS){
        TraceLog(LOG_WARNING,"Object List Full, cannot add more objects");
        return;
    }
    ObjectNode* node = &list->objects[list->count++];
    node->objectID = list->count; // Simple ID assignment
    node->object = object;
}

void ObjectListGet(ObjectList* list, int objectId, Object* outObject){
    for(int i = 0; i < list->count; i++){
        if(list->objects[i].objectID == objectId){
            *outObject = list->objects[i].object;
            return;
        }
    }
    outObject = NULL;
}

void ObjectListRemove(ObjectList* list, int objectId){
    for(int i = 0; i < list->count; i++){
        if(list->objects[i].objectID == objectId){
            // Shift remaining objects
            for(int j = i; j < list->count - 1; j++){
                list->objects[j] = list->objects[j + 1];
            }
            list->count--;
            return;
        }
    }
}

ObjectNode* ObjectListToArray(ObjectList* list,int* outCount){
    *outCount = list->count;
    ObjectNode* array = (ObjectNode*)malloc(sizeof(ObjectNode) * list->count);
    for(int i = 0; i < list->count; i++){
        array[i] = list->objects[i];
    }
    return array;
}