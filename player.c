#include "resource.h"
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
    SpriteInit(&player->sprite);
    Animation * animation = AnimationBuilder((const int[]){RSOURCE_DUCK_WALK_0, RSOURCE_DUCK_WALK_1}, 2, 5, true);
    player->sprite.animations = animation;
    player->sprite.animationCount = 1;
}

void PlayerUpdate(Player* player){
    SpriteUpdate(&player->sprite);

}

void PlayerDraw(const Player* player) {
   SpriteDraw(&player->sprite, player->x, player->y);
}