#include <pspctrl.h>
#include "input.h"

void UpdateInput(enum Actions* currentAction)
{
    SceCtrlLatch latchData;

    sceCtrlReadLatch(&latchData);

    if(latchData.uiMake & PSP_CTRL_CROSS)
    {
        *currentAction = ACTION_JUMP;
    }
    else if(latchData.uiMake & PSP_CTRL_DOWN)
    {
        *currentAction = ACTION_DUCK;
    }
    else if(latchData.uiMake & PSP_CTRL_START)
    {
        *currentAction = ACTION_START;
    }
    else if(latchData.uiMake & PSP_CTRL_SELECT)
    {
        *currentAction = ACTION_PAUSE;
    }
    else
    {
        *currentAction = ACTION_NONE;
    }
}