#include "raylib.h"

struct Warrior {
    Color COLOR;
    int health;
    int damage;
};

void DrawMenu()
{
    int positionX = 50;
    int positionY = 100;
    int width = 150;
    int height = 50;
    for (int i = 0; i < 5; i++)
    {
        DrawRectangle(positionX, positionY + (i * 100), width, height, LIGHTGRAY);
	DrawRectangleLines(positionX, positionY + (i * 100), width, height, BLACK);
	DrawText("Ball", positionX, positionY + (i * 100), 32, BLACK);       
    }
}

void DrawBalls()
{
    DrawCircle(100, 300, 50, RED);
}

int main(void)
{
    InitWindow(600, 600, "Arena Sim");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);

	    DrawBalls();
	    DrawMenu();
            DrawText("WIP: Arena Simulator", 190, 300, 20, LIGHTGRAY);
	    
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
