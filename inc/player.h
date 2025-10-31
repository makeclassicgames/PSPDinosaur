#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include <stdbool.h>

#include "sprite.h"
#include "engine.h"

#define WALK_ANIMATION 0
#define DUCK_ANIMATION 1

typedef struct player{
    Entity entity;
    int jumpStrength;
    bool isJumping;
}Player;

void PlayerInit(Player* player, int x, int y, int width, int height, int jumpStrength);
void PlayerUpdate(Player* player);
void PlayerDraw(const Player* player);
#endif // PLAYER_H