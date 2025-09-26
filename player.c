#include "player.h"
#include <raylib.h>

void PlayerInit(Player* player, int x, int y, int width, int height, int jumpStrength) {
    player->x = x;
    player->y = y;
    player->width = width;
    player->height = height;
    player->velocity = 0;
    player->jumpStrength = jumpStrength;
    player->isJumping = false;
}

void PlayerUpdate(Player* player){

}

void PlayerDraw(const Player* player) {
    DrawRectangle(player->x, player->y, player->width, player->height, BLUE);
}