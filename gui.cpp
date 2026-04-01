#include "gui.h"
#include <cstdlib>
#include <string>

//
//  Test GUI Display
//

Gui::Gui()
{

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
    if(progress < 1.0){progress += 0.01;};
}


//
//  Ability Scores Display
//
AbilityScoreGui::AbilityScoreGui(){
    
}

// could probably make just one instead of 
// per ability. make it take inputs (like position and 
// ability name). 
void AbilityScoreGui::createProgressBar(){
    // struct Rect. {x, y, width, height}
    // get window dimensions from main
    // later set window dimensions in separate file
    Rectangle strengthProgBar = {150, 900, 100, 50};
    // Draw bar background
    DrawRectangleRec(strengthProgBar, LIGHTGRAY);
    // Draw border
    DrawRectangleLinesEx(strengthProgBar, 2, SKYBLUE);
    // Draw fill
    Rectangle filledBar = strengthProgBar;
    filledBar.width *= progress;
    DrawRectangleRec(filledBar, SKYBLUE);
    // Progress Text
    char percentText[16];
    snprintf(percentText, sizeof(percentText), "%d%%", (int)(progress * 100));
    int textWidth = MeasureText(percentText, 20);
    DrawText(percentText, strengthProgBar.x + (strengthProgBar.width - textWidth) / 2, strengthProgBar.y + 5, 20, BLACK);
}

void AbilityScoreGui::updateProgressBar(Gui x){
    if(x.progress > 0.5){
        progress += .01;
        if(progress > 1.0){
            progress = 0.0;
        }
        x.progress = 0.f;
    }
}