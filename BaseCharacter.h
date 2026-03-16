#include "raylib.h"
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

class BaseCharacter{
    public: 
        BaseCharacter();
        Vector2 getWorldPos(){return worldPos;}
        void undoMovement();
        Rectangle GetCollisionRec();
        virtual void tick(float deltaTime);
        virtual Vector2 getScreenPos() = 0; // can only be derived
        // bool getAlive(){return alive;}
        // void setAlive(bool isAlive){alive = isAlive;}
    
    protected:
        // fill in with character spritesheet info
        Texture2D texture{LoadTexture("tile_sets/Modern tiles_Free/Characters_free/Adam_idle_anim_16x16.png")};
        Texture2D idle{LoadTexture("tile_sets/Modern tiles_Free/Characters_free/Adam_idle_anim_16x16.png")};
        Texture2D run{LoadTexture("tile_sets/Modern tiles_Free/Characters_free/Adam_run_16x16.png")};
        Vector2 screenPos{};
        Vector2 worldPos{};
        Vector2 worldPosLastFrame{};

        // Facing right: 1
        // Facing left: -1
        float rightLeft{1.f};

        // Animation variables
        float runningTime{};
        int frame{};
        int maxFrames{6};
        float updateTime{1.f/12.f};
        float speed{4.f};
        float width{};
        float height{};
        float scale{4.0f};
        Vector2 velocity{};

    private:
        bool alive{true};
};

#endif