#include <stdio.h>
#include <raylib.h>

int main() {
    const int ScreenWidth = 800;
    const int screenheight = 600;
    const int framerate = 60;

    InitWindow(ScreenWidth, screenheight, "Hello, World!");
    SetTargetFPS(framerate);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GREEN);
        //snake drawing stuff
        DrawRectangle(400, 300, 50, 50, RED);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}