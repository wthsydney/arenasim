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

// TODO(Patryk):

// void DrawButton(int posX, int posY, int width, int height, const char* text)
// {
//     // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
//     Vector2 mousePos = GetMousePosition();
//     int buttonState = 0;
//     Color buttonColor;
//     DrawRectangle(posX, posY, width, height, buttonColor);
//     DrawRectangleLines(posX, posY, width, height, BLACK);
//     DrawText(text, posX + 10, posY, 24, BLACK);

//     Rectangle buttonBounds = {posX, posY, width, height};
//     if (CheckCollisionPointRec(mousePos, buttonBounds))
//     {
// 	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) buttonColor = BLUE;
// 	else buttonState = 1;

// 	// if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
//     }
//     else buttonState = 0;
// }

void DrawButton(int posX, int posY, int width, int height, const char* text, bool isSelected)
{
    Vector2 mousePos = GetMousePosition();
    Rectangle buttonBounds = {(float)posX, (float)posY, (float)width, (float)height};
    
    // Logic: If it's already selected, keep it blue. 
    // Otherwise, check for hover/click.
    Color buttonColor = LIGHTGRAY;
    
    if (isSelected) 
    {
        buttonColor = RED;
    }
    else if (CheckCollisionPointRec(mousePos, buttonBounds))
    {
        buttonColor = GRAY; // Hover color
    }

    DrawRectangleRec(buttonBounds, buttonColor);
    DrawRectangleLines(posX, posY, width, height, BLACK);
    DrawText(text, posX + 10, posY + 10, 20, BLACK);
}

// int selectedBall = -1;

// void DrawMenu()
// {
 
//     int positionX = 50;
//     int positionX2 = 400;
//     int positionY = 100;
//     int width = 150;
//     int height = 50;
//     int x = 50;
//     int y = 100;
//     int w = 150;
//     int h = 50;
//     const char* balls[] = {"Unarmed", "Sword", "Spear", "Duplicator", "Dagger"};
//     Vector2 mousePos = GetMousePosition();
//     DrawText("Chose ball no.1", positionX-10, positionY-75, 24, BLACK);
//     for (int i = 0; i < 5; i++)
//     {
//         Rectangle bounds = {(float)x, (float)y, (float)w, (float)h};
//         if (CheckCollisionPointRec(mousePos, bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//         {
//             selectedBall = i; // Save the choice!
//         }

//         DrawButton(x, y + (i * 100), w, h, balls[i], (selectedBall == i));
//     }

//     DrawText("Chose ball no.2", positionX2, positionY-75, 24, BLACK);
//     for (int i = 0; i < 5; i++)
//     {
 
//     }

//     DrawRectangle(275, 275, height, height, YELLOW);
//     DrawRectangleLines(275, 275, height, height, BLACK);
// }

global_variable int selectedBall = -1;

internal void
DrawMenu()
{
    const char* balls[] = {"Unarmed", "Sword", "Spear", "Duplicator", "Dagger"};
    Vector2 mousePos = GetMousePosition();

    DrawText("Choose ball no.1", 40, 25, 20, BLACK);

    for (int i = 0; i < 5; i++)
    {
        int x = 50;
        int y = 100 + (i * 100);
        int w = 150;
        int h = 50;

        // Check if THIS specific button is the one the user clicked
        Rectangle bounds = {(float)x, (float)y, (float)w, (float)h};
        if (CheckCollisionPointRec(mousePos, bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            selectedBall = i; // Save the choice!
        }

        // Draw the button, telling it if it should be blue (isSelected)
        DrawButton(x, y, w, h, balls[i], (selectedBall == i));
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
