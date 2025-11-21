#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "objects.h"

typedef struct background{
    Texture2D* texture;
    Vector2 position;
    float scaleFactor;
    float scrollSpeed;
}Background;

// Game-related declarations go here
enum GameStates {
    GAME_INIT,
    GAME_RUNNING,
    GAME_PAUSED,
    GAME_OVER
};
#define MAX_BACKGROUNDS 4
struct{
    int score;
    enum Actions currentAction;
    Player player;
    ObjectList cactusList;
    Timer obstacleTimer;
    enum GameStates state;
    Texture2D background;
    Background backgrounds[MAX_BACKGROUNDS];
    int backgroundCount;
} game;

void BackgroundInit(Background* bg, Texture2D* texture,Vector2 initialPosition, float scaleFactor, float scrollSpeed);
void BackgroundUpdate(Background* bg);
void BackgroundDraw(const Background* bg);
#define JUMP_STRENGTH 7
#define GRAVITY 20.0f
#endif // GAME_H