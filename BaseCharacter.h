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
    
    // protected: can be modified in this class
    // and from inheriting classes (character.h)
    protected:
        // fill in with character spritesheet info
        // to edit in aseprite, open from GameDev c/ directory
        // and save to GameJam tiles directory
        Texture2D texture{LoadTexture("tile_sets/Modern tiles_Free/Characters_free/inProgress/Adam_idle_anim_leftRight_16x16.png")};
        Texture2D idle{LoadTexture("tile_sets/Modern tiles_Free/Characters_free/inProgress/Adam_idle_anim_leftRight_16x16.png")};
        Texture2D runVert{LoadTexture("tile_sets/Modern tiles_Free/Characters_free/inProgress/Adam_run_upDown_16x16.png")};
        Texture2D runHoriz{LoadTexture("tile_sets/Modern tiles_Free/Characters_free/inProgress/Adam_run_leftRight_16x16.png")};
        Vector2 screenPos{};
        Vector2 worldPos{};
        Vector2 worldPosLastFrame{};

        // Facing right/up: 1
        // Facing left/down: -1
        float rightLeft{1.f};
        float upDown{1.f};


        // Animation variables
        float runningTime{};
        // subdivided png
        float frame{};
        int maxFrames{6};
        float updateTime{1.f/12.f};
        float speed{4.f};
        float width{};
        float height{};
        float scale{4.0f};
        Vector2 velocity{};

        // Stat Block
        int strength{0};
        int agility{0};
        int intelligence{0};

    private:
        bool alive{true};
};

#endif