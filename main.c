/*******************************************************************************************
 *
 *   raylib [shapes] example - Draw basic shapes 2d (rectangle, circle, line...)
 *
 *   Example originally created with raylib 1.0, last time updated with raylib 4.2
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
 *   BSD-like license that allows static linking with closed source software
 *
 *   Copyright (c) 2014-2024 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <raylib.h>

#include "input.h"
#include "game.h"
#include "objects.h"
#include "resource.h"

void InitGame(void);
void Update(void);
void Draw(void);

//Init State
void InitStart(void);
void UpdateInitState(void);
void DrawInitState(void);

//Running State
void InitRunning(void);
void UpdateRunningState(void);
void DrawRunningState(void);

//Paused State
void InitPaused(void);
void UpdatePausedState(void);
void DrawPausedState(void);

//Game Over State
void InitGameOver(void);
void UpdateGameOverState(void);
void DrawGameOverState(void);

void spawnCactus();


PSP_MODULE_INFO("Dinosaur", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

#define ATTR_PSP_WIDTH 480
#define ATTR_PSP_HEIGHT 272

#define MAX_PLAYER_Y (ATTR_PSP_HEIGHT - 75)

//SceCtrlData pad;
SceCtrlLatch latchData;

bool flag = true;
bool l1flag = false;
bool r1flag = false;
int xflag;




bool initApp()
{
    return true;
}
void finishApp()
{

    ResourceManagerUnload();
}
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = ATTR_PSP_WIDTH;
    const int screenHeight = ATTR_PSP_HEIGHT;

    InitWindow(screenWidth, screenHeight, "Dinosaur");

    InitGame();

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------

    // Main game loop
    while (flag) // Detect window close with Start button
    {
        // update
        Update();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        Draw();
        
        EndDrawing();

        //-----------------------------------------------------
    }

    // De-Initialization
    //---------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //----------------------------------------------------------

    finishApp();
    return 0;
}
void InitGame(void)
{
    // Initialize your variables here
    //--------------------------------------------------------------------------------------
    game.score = 0;
    game.state = GAME_INIT;
    ResourceManagerInit();
    PlayerInit(&game.player, 40, MAX_PLAYER_Y, 50, 50, JUMP_STRENGTH);
    EntitySetCollider(&game.player.entity,(Collider){5,5,24,28});
    TimerInit(&game.obstacleTimer,SECONDS_TO_FRAME(3),true,false,spawnCactus);
    ObjectListInit(&game.cactusList);
    //--------------------------------------------------------------------------------------
}
void Update()
{
    // Update your variables here
    // Update
    //-----------------------------------------------------
    UpdateInput(&game.currentAction);
    

    switch (game.state)
    {
    case GAME_INIT:
       UpdateInitState();
       break;
    case GAME_RUNNING:
        UpdateRunningState();
        break;
    case GAME_PAUSED:
        UpdatePausedState();
        break;
    case GAME_OVER:
        UpdateGameOverState();
        break;
    }
    //-----------------------------------------------------
}

void Draw()
{
    // Draw your variables here
    ClearBackground(RAYWHITE);

    PlayerDraw(&game.player);
    
    switch (game.state)
    {
    case GAME_INIT:
        DrawInitState();
        break;
    case GAME_RUNNING:
        DrawRunningState();
        break;
    case GAME_PAUSED:
        DrawPausedState();
        break;
    case GAME_OVER:
        DrawGameOverState();
        break;
    default:
        break;
    }
}

void UpdateInitState(void)
{
    if(game.currentAction == ACTION_START)
    {
        game.state = GAME_RUNNING;
        InitRunning();
    }
}

void DrawInitState(void)
{
    DrawText("Press START to begin!", 100, 130, 20, LIGHTGRAY);
    PlayerDraw(&game.player);
}

void InitRunning(void)
{
    // Initialize Running state variables here
    TimerStart(&game.obstacleTimer);
    
}

void UpdateRunningState(void)
{
  
    if(game.currentAction == ACTION_DUCK){
        SpriteSetSpriteAnimation(&game.player.entity.sprite,DUCK_ANIMATION);
    }else{
        SpriteSetSpriteAnimation(&game.player.entity.sprite,WALK_ANIMATION);
    }

    if(game.currentAction == ACTION_START){
        game.state = GAME_PAUSED;
        InitPaused();
    }
    if(game.currentAction == ACTION_JUMP && !game.player.isJumping){
        game.player.isJumping = true;
        game.player.entity.velocity.y = -game.player.jumpStrength;
    }
    PlayerUpdate(&game.player);
    if(game.player.isJumping){
        float dt = GetFrameTime();
        game.player.entity.velocity.y += GRAVITY * dt; // Gravity effect

        if(game.player.entity.position.y >= MAX_PLAYER_Y){
            game.player.entity.position.y = MAX_PLAYER_Y;
            game.player.isJumping = false;
            game.player.entity.velocity.y = 0;
        }
    }
    TimerUpdate(&game.obstacleTimer);
    int cactusCount = game.cactusList.count;
    
    for(int i=0;i<cactusCount;i++){
        ObjectNode* objNode =&game.cactusList.objects[i];
        ObjectUpdate(&objNode->object);
        if(objNode->object.entity.position.x<16){
            ObjectListRemove(&game.cactusList,objNode->objectID);
            continue;
        }
        Rectangle playerRect = getRectangleFromCollider(&game.player.entity);
        Rectangle objectRect = getRectangleFromCollider(&objNode->object.entity);
        if(CheckCollisionRecs(playerRect,objectRect)){
            game.state = GAME_OVER;
            InitGameOver();
            return;
        }
    }
}

void DrawRunningState(void)
{
    PlayerDraw(&game.player);
    int cactusCount = game.cactusList.count;
   
    for(int i=0;i<cactusCount;i++){
        ObjectNode* objNode = &game.cactusList.objects[i];
        ObjectDraw(&objNode->object);
    }
    
}

void spawnCactus(){
    Object* object = (Object*)malloc(sizeof(Object));

    ObjectInit(object, ATTR_PSP_WIDTH+40, MAX_PLAYER_Y, CACTUS0);
    object->entity.velocity.x = -2;
    EntitySetCollider(&object->entity, (Collider){2,5,12,23});
    ObjectListAdd(&game.cactusList, *object);
    
}

void InitPaused(void)
{
    TimerStop(&game.obstacleTimer);
}

void UpdatePausedState(void)
{
    if(game.currentAction == ACTION_START){
        game.state = GAME_RUNNING;
    }
}

void DrawPausedState(void)
{
    DrawText("Game Paused. Press START to resume.", 50, 130, 20, LIGHTGRAY);
    PlayerDraw(&game.player);
}

void InitGameOver(void)
{
    // Initialize Game Over state variables here
}

void UpdateGameOverState(void)
{
    if(game.currentAction == ACTION_START){
        game.state = GAME_RUNNING;
        TimerStart(&game.obstacleTimer);
    }
}

void DrawGameOverState(void)
{
    DrawText("Game Over", 150, 130, 20, LIGHTGRAY);
    PlayerDraw(&game.player);
}