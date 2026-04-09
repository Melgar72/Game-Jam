#include "gui.h"
#include <cstdlib>
#include <string>

//
//  Test GUI Display
//  
//  Can be repurposed for:
// 
//  Day Night Cycle
//  Generic bar/meter for minigames
//

Gui::Gui(){

}

void Gui::createProgressBar(int win_width, int win_height){
    // struct Rect. {x, y, width, height}
    // get window dimensions from main
    // later set window dimensions in separate file
    Rectangle progressBar = {0, win_height / 1.1, 100, 50};
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
    if(progress < 1.0){progress += 0.01;}
    // Comment out when testing 
    // AbilityScoreGui::updateProgressBar(Gui x)
    else(progress = 0.0); 
}


//
//  Ability Scores Display
//
AbilityScoreGui::AbilityScoreGui(){
    
}

// could probably make just one instead of 
// per ability. make it take inputs (like position and 
// ability name). 
void AbilityScoreGui::createProgressBar(int win_width, int win_height){
    // struct Rect. {x, y, width, height}
    // get window dimensions from main
    // later set window dimensions in separate file
    Rectangle strengthProgBar = {win_width / 8, win_height / 1.1, 100, 50};
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
    if(x.progress > 1.0){
        progress += .01;
        if(progress > 1.0){
            progress = 0.0;
        }
        // Check with Grant
        // Modifying values of variables
        // from other functions. 
        // The below variable belongs to 
        // Gui and can be read, but can't/won't 
        // update. 
        //x.progress = 0.0;
    }
}