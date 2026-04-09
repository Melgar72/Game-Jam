// including Character to update ability scores
// may need to include BaseCharacter instead
// Character has raylib included
// include raylib as needed
#include "Character.h"

#ifndef MINIGAMES_H
#define MINIGAMES_H

// 
//  Test Basic Mini Games
//  
//  Start off with button timing / mashing games. 
//  Ex: Hit center of meter bar as cursor goes back and forth.
//      Mash button to move meter bar up to ceiling point.
//      Using velocity/accel, keep meter bar in a specified zone. 
//

class GenericTimingGame{
    public:
        GenericTimingGame();
        int cursorBarPos{0};
        int cursorPosToggle{0};
        int cursorPosSpeed{5};
        Rectangle createGameBar(int win_width, int win_height);
        Rectangle createCursorBar(Rectangle);
        void moveCursorBarPos(Rectangle, Rectangle);
};

#endif