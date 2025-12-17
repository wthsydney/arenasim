#include "raylib.h"

void
DrawBalls(int posX, int posY)
{
    DrawCircle(posX, posY, 50, RED);
}

int main(void)
{
    InitWindow(600, 600, "Arena Sim");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

	    DrawBalls(100, 100);
            DrawText("WIP: Arena Simulator", 190, 300, 20, LIGHTGRAY);
	    
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
