#ifndef INPUT_H
#define INPUT_H

enum Actions{
    ACTION_NONE,
    ACTION_JUMP,
    ACTION_DUCK,
    ACTION_START,
    ACTION_PAUSE
};

void UpdateInput(enum Actions*);

#endif // INPUT_H