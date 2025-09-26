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

void InitGame(void);
void Update(void);
void Draw(void);

PSP_MODULE_INFO("Dinosaur", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

#define ATTR_PSP_WIDTH 480
#define ATTR_PSP_HEIGHT 272

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
    PlayerInit(&game.player, 50, ATTR_PSP_HEIGHT - 100, 50, 50, 10);
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
       if(game.currentAction == ACTION_JUMP)
       {
           game.state = GAME_RUNNING;
       }
       break;
    case GAME_RUNNING:
       if(game.currentAction == ACTION_JUMP){
           game.state = GAME_PAUSED;
       }
        break;
    case GAME_PAUSED:
        if(game.currentAction == ACTION_JUMP){
            game.state = GAME_OVER;
        }
        break;
    case GAME_OVER:
        if(game.currentAction == ACTION_JUMP){
            game.state = GAME_INIT;
        }
        break;
    }
    //-----------------------------------------------------
}

void Draw()
{
    // Draw your variables here
    ClearBackground(RAYWHITE);

    DrawText("Dinosaur", 20, 20, 20, DARKGRAY);
    PlayerDraw(&game.player);
    switch (game.state)
    {
    case GAME_INIT:
        DrawText("Press X to Start", 150, 130, 20, LIGHTGRAY);
        break;
    case GAME_RUNNING:
        DrawText("Game Running", 150, 130, 20, LIGHTGRAY);
        break;
    case GAME_PAUSED:
        DrawText("Game Paused", 150, 130, 20, LIGHTGRAY);
        break;
    case GAME_OVER:
        DrawText("Game Over", 150, 130, 20, LIGHTGRAY);
        break;
    default:
        break;
    }
}