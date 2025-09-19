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

PSP_MODULE_INFO("Dinosaur", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

#define ATTR_PSP_WIDTH 480
#define ATTR_PSP_HEIGHT 272

SceCtrlData pad;

bool flag=true;
bool l1flag=false;
bool r1flag=false;
int xflag;

void updateController()
{
    sceCtrlReadBufferPositive(&pad, 1);


    if (pad.Buttons != 0)
    {
        if (pad.Buttons & PSP_CTRL_SQUARE)
        {
            TraceLog(LOG_INFO,"Square pressed \n");
        }
        
        if (pad.Buttons & PSP_CTRL_TRIANGLE)
        {
            TraceLog(LOG_INFO,"Triangle pressed \n");
        } 
        
        if (pad.Buttons & PSP_CTRL_CIRCLE)
        {
            TraceLog(LOG_INFO,"Cicle pressed \n");
        } 
        
        if (pad.Buttons & PSP_CTRL_CROSS)
        {
            TraceLog(LOG_INFO,"Cross pressed \n");
            xflag = !xflag;
        } 

        if (pad.Buttons & PSP_CTRL_UP)
        {
            TraceLog(LOG_INFO,"Up pressed \n");
        } 
        
        if (pad.Buttons & PSP_CTRL_DOWN)
        {
            TraceLog(LOG_INFO,"Down pressed \n");
        } 
        
        if (pad.Buttons & PSP_CTRL_LEFT)
        {
            TraceLog(LOG_INFO,"Left pressed \n");
        } 
        
        if (pad.Buttons & PSP_CTRL_RIGHT)
        {
            TraceLog(LOG_INFO,"Right pressed \n");
        }      

        if (pad.Buttons & PSP_CTRL_START)
        {
            TraceLog(LOG_INFO,"Start pressed \n");
            flag=0;
        }
        
        if (pad.Buttons & PSP_CTRL_SELECT)
        {
            TraceLog(LOG_INFO,"Select pressed \n");
        }
        
        if (pad.Buttons & PSP_CTRL_LTRIGGER)
        {
            TraceLog(LOG_INFO,"L-trigger pressed \n");
        }
        
        if (pad.Buttons & PSP_CTRL_RTRIGGER)
        {
            TraceLog(LOG_INFO,"R-trigger pressed \n");
        }      
    }
}


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
    
    float rotation = 0.0f;

   

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------

    // Main game loop
    while (flag)    // Detect window close with Start button
    {
        // Update
        //-----------------------------------------------------
        updateController();

         //----------------------------------------------------------------------------------
        rotation += 0.2f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Dinosaur", 20, 20, 20, DARKGRAY);

           
        EndDrawing();

    
        //-----------------------------------------------------
    }

    // De-Initialization
    //---------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //----------------------------------------------------------
    
    finishApp();
    return 0;
}
