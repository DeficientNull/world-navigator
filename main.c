#include <stdio.h>
#include <raylib.h>
#include <raymath.h>
#include <resource_dir.h>

int main() {
    const int ScreenWidth = 800;
    const int Screenheight = 600;
    const int framerate = 14;
     
    float PlayerSizeX = 20.0f;
    float PlayerSizeY = 20.0f;
    float PlayerPosX = 400.0f;
    float PlayerPosY = 300.0f;
    float PlayerVelocityX = 20.0f;
    float PlayerVelocityY = 20.0f;

    Vector2 PlayerPosition = {(float)PlayerPosX,(float)PlayerPosY};
    Vector2 PlayerSize = {(float)PlayerSizeX,(float)PlayerSizeY};

    int WallSizeX = 140;
    int WallSizeY = 100;
    int WallPositionX = 40;
    int WallPositionY = 400;
    
    InitWindow(ScreenWidth, Screenheight, "Pathfinder");
    SetTargetFPS(framerate);

    // stuff that happens every frame
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawFPS(20, 20);
        //player drawing stuff
        DrawRectangleV(PlayerPosition, PlayerSize, BLUE);
        
        //player input stuff
        if (IsKeyDown(KEY_W)) {
            PlayerPosition.x = 0.0f;
            PlayerPosition.y -= PlayerVelocityY;
        }
        if (IsKeyDown(KEY_S)) {
            PlayerPosition.x = 0.0f;
            PlayerPosition.y += PlayerVelocityY;
        }
        if (IsKeyDown(KEY_D)) {
            PlayerPosition.x += PlayerVelocityX;
            PlayerPosition.y = 0.0f;
        }
        if (IsKeyDown(KEY_A)) {
            PlayerPosition.x -= PlayerVelocityX;
            PlayerPosition.y = 0.0f;
        }
        
        //Wall Drawing
        DrawRectangle(WallPositionX, WallPositionY, WallSizeX, WallSizeY, GRAY);
        

        //wall collision stuff
        if (PlayerPosition.x == 20.0f) {
            if (IsKeyDown(KEY_D)) {
                PlayerVelocityX = 0.0f;
            }
        } else {
            PlayerVelocityX = 0.0f;
        }
        if (PlayerPosition.y == 380.0f) {
            if (IsKeyDown(KEY_S)) {
                PlayerVelocityY = 0.0f;
            }
        } else {
            PlayerVelocityY = 0.0f;
        }
        //this is insane, i'll end up having to manually write every coordinate for every wall i need collision for
        //well it doesn't even work right so it doesn't matter
        EndDrawing();
    }
    CloseWindow();
    
    return 0;
}