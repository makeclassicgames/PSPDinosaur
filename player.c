#include "player.h"
#include <raylib.h>
#include <pspdebug.h>


void PlayerInit(Player* player, int x, int y, int width, int height, int jumpStrength) {
    player->x = x;
    player->y = y;
    player->width = width;
    player->height = height;
    player->velocity = 0;
    player->jumpStrength = jumpStrength;
    player->isJumping = false;
    SpriteInit(&player->sprite, "host0:/dinosaur/PATO1.png");
}

void PlayerUpdate(Player* player){

}

void PlayerDraw(const Player* player) {
   SpriteDraw(&player->sprite, player->x, player->y);
}