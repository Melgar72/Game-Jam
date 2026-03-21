#include "gui.h"
#include <cstdlib>
#include <string>

Gui::Gui(){

}

void Gui::createProgressBar(){
    // struct Rect. {x, y, width, height}
    // get window dimensions from main
    // later set window dimensions in separate file
    Rectangle progressBar = {0, 900, 100, 50};
    // Draw progress bar background
    DrawRectangleRec(progressBar, LIGHTGRAY);
    // Draw border
    DrawRectangleLinesEx(progressBar, 2, DARKGRAY);
    // Draw fill
    Rectangle filledBar = progressBar;
    filledBar.width *= progress;
    DrawRectangleRec(filledBar, SKYBLUE);
    // Progress Text
    char percentText[16];
    snprintf(percentText, sizeof(percentText), "%d%%", (int)(progress * 100));
    int textWidth = MeasureText(percentText, 20);
    DrawText(percentText, progressBar.x + (progressBar.width - textWidth) / 2, progressBar.y + 5, 20, BLACK);
}

void Gui::updateProgressBar(){
    // Test update progressbar
    if(progress <= 1.0){progress += 0.001;};
}