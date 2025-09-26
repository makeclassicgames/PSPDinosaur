#ifndef GAME_H
#define GAME_H
#include "player.h"
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
    enum GameStates state;
} game;
#endif // GAME_H