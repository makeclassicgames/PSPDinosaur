#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include <stdbool.h>

#include "sprite.h"

typedef struct player{
    int x;
    int y;
    int width;
    int height;
    int velocity;
    int jumpStrength;
    bool isJumping;
    Sprite sprite;
}Player;

void PlayerInit(Player* player, int x, int y, int width, int height, int jumpStrength);
void PlayerUpdate(Player* player);
void PlayerDraw(const Player* player);
#endif // PLAYER_H