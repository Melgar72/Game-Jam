#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{

}

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::GetCollisionRec()
{
    return Rectangle 
    {
        getScreenPos().x, 
        getScreenPos().y, 
        width * scale, 
        height * scale
    };
}

void BaseCharacter::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;
    
    // Update animation frame
    // BaseCharacter.h has constants set
    // update constants for diff sprites
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }

    if (Vector2Length(velocity) != 0.0)
    {
        // Set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));

        // Revisit
        /*
         * Create idle animation
         * textures for each direction. 
         * Update if/else to dictate
         * direction facing properly.
         * revisit runVert, weird frame 
         * flickering and only faces down.
        */
        if(velocity.x < 0.f){
            rightLeft = -1.f;
            texture = runHoriz;
        } else if (velocity.x > 0.f){
            rightLeft = 1.f;
            texture = runHoriz;
        }

        if(velocity.y < 0.f){
            upDown = -1.f;
            texture = runVert;
        } else if(velocity.y > 0.f){
            upDown = 1.f;
            texture = runVert;
        }
    }
    else
    {
        texture = idle;
    }
    velocity = {};

    // Draw character
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}