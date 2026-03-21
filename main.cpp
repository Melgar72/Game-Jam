#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include <string>

int main(){
    // Window dimensions
    const int win_width{1000};
    const int win_height{1000};

    InitWindow(win_width, win_height, "Summer Training");
    SetTargetFPS(60);

    // Map
    Texture2D map = LoadTexture("tile_sets/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0}; // verify position
    const float mapScale{4.0f}; // verify scale

    // Set character
    Character player{win_width, win_height};

    // fill...

    // Game window is open
    while (!WindowShouldClose()){
        // Start drawing
        BeginDrawing();
        ClearBackground(BLACK); 

        // Draw map
        mapPos = Vector2Scale(player.getWorldPos(), -1.f);
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        // Update frames on player
        player.tick(GetFrameTime());
        
        // Check map bounds
        if( player.getWorldPos().x < 0.f ||
            player.getWorldPos().y < 0.f ||
            player.getWorldPos().x + win_width > map.width * mapScale ||
            player.getWorldPos().y + win_height > map.height * mapScale
        ){
            player.undoMovement();
        }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}