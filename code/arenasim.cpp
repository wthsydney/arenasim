#include "raylib.h"

struct Warrior {
    Color COLOR;
    int health;
    int damage;
};

const char* DrawMenu()
{
    int positionX = 50;
    int positionX2 = 400;
    int positionY = 100;
    int width = 150;
    int height = 50;
    const char* balls[] = {"Unarmed", "Sword", "Spear", "Duplicator", "Dagger"};
    DrawText("Chose ball no.1", positionX-10, positionY-75, 24, BLACK);
    for (int i = 0; i < 5; i++)
    {
        DrawRectangle(positionX, positionY + (i * 100), width, height, LIGHTGRAY);
	DrawRectangleLines(positionX, positionY + (i * 100), width, height, BLACK);
	DrawText(balls[i], positionX + 10, positionY + 10 + (i * 100), 24, BLACK);       
    }

    DrawText("Chose ball no.2", positionX2, positionY-75, 24, BLACK);
    for (int i = 0; i < 5; i++)
    {
        DrawRectangle(positionX2, positionY + (i * 100), width, height, LIGHTGRAY);
	DrawRectangleLines(positionX2, positionY + (i * 100), width, height, BLACK);
	DrawText(balls[i], positionX2 + 10, positionY + 10 + (i * 100), 24, BLACK);       
    }

    DrawRectangle(275, 275, height, height, YELLOW);
    DrawRectangleLines(275, 275, height, height, BLACK);

    return balls[1];
}

void DrawBalls()
{
    Color BallColor = RED;
    DrawCircle(100, 300, 50, BallColor);
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
	    
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
