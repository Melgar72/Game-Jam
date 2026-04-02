#include "raylib.h"
#include "gui.h"
#include "raymath.h"
#include "Character.h"
#include "miniGames.h"
#include "MiniGameZones.h"
#include <cstdlib>
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

    // progress bars
    // from gui.h
    Gui progressBar;
    AbilityScoreGui strengthProgBar;

    // mini game
    GenericTimingGame game;
    // ignoring the minigame class
    // MiniGameZones miniGameZone;
    Texture2D standin = LoadTexture("tile_sets/Modern tiles_free/Characters_free/inProgress/standin.png");
    Vector2 standinPos{0.0, 0.0};

    // check collision between character and minigame
    bool minigameCollision = false;

    // fill...

    // Game window is open
    while (!WindowShouldClose()){
        // Start drawing
        BeginDrawing();
        ClearBackground(BLACK); 

        // Draw map
        mapPos = Vector2Scale(player.getWorldPos(), -1.f);
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        // Basic player UI
        progressBar.createProgressBar();
        progressBar.updateProgressBar();

        // Ability Score UI
        strengthProgBar.createProgressBar();
        strengthProgBar.updateProgressBar(progressBar);

        // Draw minigame zone
        // miniGameZone.makeZone();
        // refactor below to make it work from the class
        Rectangle standinRec = Rectangle{standinPos.x, standinPos.y, standin.width * mapScale, standin.height * mapScale};
        standinPos = Vector2Scale(player.getWorldPos(), -1.f) + Vector2{1000.0, 500.0};
        DrawTextureEx(standin, standinPos, 0.0, 4.0, WHITE);


        // minigame check
        // minigameCollision = CheckCollisionRecs(player.GetCollisionRec(), miniGameZone.makeZone());
        //
        // Need rectangle for below
        minigameCollision = CheckCollisionRecs(player.GetCollisionRec(), standinRec);

        // future problems:
        // Need to pause movement when in minigame
        // If paused, we need to break out of game on completion
        // When completed, unpause
        // When unpaused though, we'll still be colliding
        // Need to move character prior to unpausing,
        // or give grace period from intera
        if(minigameCollision){
            // Pause player movement
            
            // MiniGame UI (add if statement to proc)
            Rectangle bigBar = game.createGameBar();
            // game.createCursorBar(game.createGameBar());
            Rectangle smallBar = game.createCursorBar(bigBar);
            // game.moveCursorBarPos(game.createCursorBar(game.createGameBar(),));
            game.moveCursorBarPos(bigBar, smallBar);
        };

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