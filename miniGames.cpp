#include "miniGames.h"

#include <cstdlib>
#include <string>

GenericTimingGame::GenericTimingGame(){

}

Rectangle GenericTimingGame::createGameBar(int win_width, int win_height){
    // struct Rect. {x, y, width, height}
    // get window dimensions from main
    // later set window dimensions in separate file.
    // OR 
    // have createGameBar take values in function call
    // for window dimensions
    // and set gameBar rectangle in relation to those
    float gbWidth = 300.f;
    float gbHeight = 100.f;
    Rectangle gameBar = {((1.f/2.f) * win_width) - ((1.f/2.f) * gbWidth), 200, gbWidth, gbHeight};
    // Draw gameBar background
    DrawRectangleRec(gameBar, BLACK);
    // Draw border
    DrawRectangleLinesEx(gameBar, 4, LIGHTGRAY);
    return gameBar;
}

Rectangle GenericTimingGame::createCursorBar(Rectangle r){
    Rectangle cursorBar = {cursorBarPos + r.x, r.y, r.width / 10, r.height};
    DrawRectangleRec(cursorBar, BLUE);
    return cursorBar;
}

void GenericTimingGame::moveCursorBarPos(Rectangle r, Rectangle c){
    // while the cursorBar position 
    // is less than the width of the gamebar
    // increase position
    if(cursorPosToggle == 0){
        cursorBarPos += cursorPosSpeed;
        if(cursorBarPos == r.width - c.width){
            cursorPosToggle = 1;
        }
    }

    // while the cursorBar position 
    // is greater than the leftmost
    // of the gameBar
    // decrease position
    if(cursorPosToggle == 1){
        cursorBarPos -= cursorPosSpeed;
        if(cursorBarPos == 0){
            cursorPosToggle = 0;
        }
    }

    
}