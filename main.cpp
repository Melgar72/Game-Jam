#include "raylib.h"

int main(){
    // Window dimensions
    const int win_width{700};
    const int win_height{700};

    InitWindow(win_width, win_height, "Summer Training");
    SetTargetFPS(60);

    // Map
    // NEED TO SET MAP TEXTURE
    /*
        Texture2D map = LoadTexture("file");
        Vector2 mapPos{0.0, 0.0}; // verify position
        const float mapScale{4.0f}; // verify scale
    */

    // Set character
    // make character header and instatiate

    // fill...

    // Game window is open
    while (!WindowShouldClose()){
        // Start drawing
        BeginDrawing();
        ClearBackground(BLACK); 

        // mapPos() later

        EndDrawing();
    }

    CloseWindow();
}