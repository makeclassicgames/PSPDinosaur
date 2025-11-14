#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "objects.h"
// Game-related declarations go here
enum GameStates {
    GAME_INIT,
    GAME_RUNNING,
    GAME_PAUSED,
    GAME_OVER
};
struct{
    int score;
    enum Actions currentAction;
    Player player;
    ObjectList cactusList;
    Timer obstacleTimer;
    enum GameStates state;
} game;

#define JUMP_STRENGTH 7
#define GRAVITY 20.0f
#endif // GAME_H