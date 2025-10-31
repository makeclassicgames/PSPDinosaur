#include "resource.h"
#include "player.h"
#include <raylib.h>
#include <stdlib.h>
#include <pspdebug.h>


void PlayerInit(Player* player, int x, int y, int width, int height, int jumpStrength) {
   
    player->jumpStrength = jumpStrength;
    player->isJumping = false;
    Animation * animationWalk = AnimationBuilder((const int[]){RSOURCE_DUCK_WALK_0, RSOURCE_DUCK_WALK_1, RSOURCE_DUCK_WALK_2, RSOURCE_DUCK_WALK_3}, 4, 5, true);
    Animation * animationDown = AnimationBuilder((const int[]){RSOURCE_DUCK_DOWN_0, RSOURCE_DUCK_DOWN_1, RSOURCE_DUCK_DOWN_2, RSOURCE_DUCK_DOWN_3}, 4, 5, true);
    SpriteInit(&player->entity.sprite);
    player->entity.sprite.animations = (Animation*)malloc(sizeof(Animation) * 2);
    player->entity.sprite.animations[0] = *animationWalk;
    player->entity.sprite.animations[1] = *animationDown;
    player->entity.sprite.animationCount = 2;
    EntityInit(&player->entity, x, y, &player->entity.sprite);
   
}

void PlayerUpdate(Player* player){
    EntityUpdate(&player->entity);

}

void PlayerDraw(const Player* player) {
   EntityDraw(&player->entity);
}