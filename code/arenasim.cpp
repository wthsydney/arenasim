#include "raylib.h"

#define internal static
#define local_persist static
#define global_variable static

struct Warrior
{
    Color COLOR;
    int health;
    int damage;
};

internal void
DrawButton(int posX, int posY, int width, int height, const char* text, bool isSelected)
{
    Vector2 mousePos = GetMousePosition();
    Rectangle buttonBounds = {(float)posX, (float)posY, (float)width, (float)height};

    Color buttonColor = RAYWHITE;
    
    if (isSelected) 
    {
        buttonColor = GRAY;
    }
    else if (CheckCollisionPointRec(mousePos, buttonBounds))
    {
        buttonColor = LIGHTGRAY; // Hover color
    }

    DrawRectangleRec(buttonBounds, buttonColor);
    DrawRectangleLines(posX, posY, width, height, BLACK);
    DrawText(text, posX + 10, posY + 10, 20, BLACK);
}

global_variable int selectedBallS1 = 0;
global_variable int selectedBallS2 = 0;

internal void
DrawMenu()
{
    const char* balls[] = {"Unarmed", "Sword", "Spear", "Duplicator", "Dagger"};
    Vector2 mousePos = GetMousePosition();

    DrawText("Choose ball no.1", 40, 25, 20, BLACK);
    
    // Left buttons
    for (int i = 0; i < 5; i++)
    {
	int x = 50;
	int y = 100 + (i * 100);
	int w = 150;
	int h = 50;
    
        Rectangle bounds = {(float)x, (float)y, (float)w, (float)h};
        if (CheckCollisionPointRec(mousePos, bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            selectedBallS1 = i; // Save the choice!
        }

        // Draw the button, telling it if it should be blue (isSelected)
        DrawButton(x, y, w, h, balls[i], (selectedBallS1 == i));
    }

    // Right buttons
    for (int i = 0; i < 5; i++)
    {
	int x = 400;
	int y = 100 + (i * 100);
	int w = 150;
	int h = 50;
    
        Rectangle bounds = {(float)x, (float)y, (float)w, (float)h};
        if (CheckCollisionPointRec(mousePos, bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            selectedBallS2 = i; // Save the choice!
        }

        // Draw the button, telling it if it should be blue (isSelected)
        DrawButton(x, y, w, h, balls[i], (selectedBallS2 == i));
    }
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
