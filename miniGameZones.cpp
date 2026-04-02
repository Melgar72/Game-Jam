#include "MiniGameZones.h"

MiniGameZones::MiniGameZones(){

};

Rectangle MiniGameZones::makeZone(){
    // stand in basic zone
    // struct Rect. {x, y, width, height}
    Rectangle basicZone = {300, 300, 100, 100};
    // Draw the zone
    DrawRectangleRec(basicZone, BLACK);
    // Draw border
    DrawRectangleLinesEx(basicZone, 4, LIGHTGRAY);
    return basicZone;
}