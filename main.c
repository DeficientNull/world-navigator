#include <stdio.h>
#include <raylib.h>
#include <raymath.h>

int main() {
    const int ScreenWidth = 800;
    const int screenheight = 600;
    const int framerate = 14;
     
    float PlayerSizeX = 20.0f;
    float PlayerSizeY = 20.0f;
    float PlayerPosX = 400.0f;
    float PlayerPosY = 300.0f;
    float PlayerVelocity = 20.0f;

    Vector2 PlayerPosition = {
        (float)PlayerPosX, 
        (float)PlayerPosY
    };
    Vector2 PlayerSize = {
        (float)PlayerSizeX,
        (float)PlayerSizeY
    };
    
    InitWindow(ScreenWidth, screenheight, "Snake Game");
    SetTargetFPS(framerate);

    // stuff that happens every frame
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GREEN);
        
        DrawFPS(20, 20);
        //snake drawing stuff
        DrawRectangleV(PlayerPosition, PlayerSize, RED);
        
        //move the player to a direction on game start
        PlayerPosition.x += 20.0f;
        
        //player input stuff
        if (IsKeyPressed(KEY_W)) {
            PlayerPosition.x == 0.0f;
            PlayerPosition.y -= 20.0f;
        }
        if (IsKeyPressed(KEY_S)) {
            PlayerPosition.x == 0.0f;
            PlayerPosition.y += 20.0f;
        }
        if (IsKeyPressed(KEY_D)) {
            PlayerPosition.x += 20.0f;
            PlayerPosition.y == 0.0f;
        }
        if (IsKeyPressed(KEY_A)) {
            PlayerPosition.x -= 20.0f;
            PlayerPosition.y == 0.0f;
        }

        EndDrawing();
    }
    CloseWindow();

    return 0;
}