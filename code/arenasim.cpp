#include "raylib.h"
#include <stdio.h>

#define internal static
#define local_persist static
#define global_variable static

// TODO(Patryk): Those are global for now
global_variable int selectedBallS1 = 0;
global_variable int selectedBallS2 = 0;

struct Warrior
{
    Color COLOR;
    int health;
    int damage;
    int speed;
};

internal void
RenderGame()
{
    CloseWindow();
}

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
	// Hover color
        buttonColor = LIGHTGRAY;
    }

    DrawRectangleRec(buttonBounds, buttonColor);
    DrawRectangleLines(posX, posY, width, height, BLACK);
    DrawText(text, posX, posY, 20, BLACK);
}

// TODO: Figure out how to NOT return multiple variables
internal int
DrawMenu()
{
    const char* balls[] = {"Unarmed", "Sword", "Spear", "Grower", "Dagger"};
    Vector2 mousePos = GetMousePosition();

    DrawText("Choose ball no.1", 40, 25, 20, BLACK);

    // TODO(Patryk): For some reason when I take the properties outside the
    // function, something's wrong.
    
    // Left buttons
    for (int i = 0; i < 5; i++)
    {
	int x = 50;
	int y = 100 + (i * 100);
	int w = 150;
	int h = 50;
    
        Rectangle bounds = {(float)x, (float)y, (float)w, (float)h};
        if (CheckCollisionPointRec(mousePos, bounds)
	    && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
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
        if (CheckCollisionPointRec(mousePos, bounds)
	    && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            selectedBallS2 = i; // Save the choice!
        }

        // Draw the button, telling it if it should be blue (isSelected)
        DrawButton(x, y, w, h, balls[i], (selectedBallS2 == i));
    }

    int px = 255;
    int py = 300;
    int pw = 90;
    int ph = 30;
    Rectangle playButtonBounds = {(float)px, (float)py, (float)pw, (float)ph};
    if (CheckCollisionPointRec(mousePos, playButtonBounds)
	&& IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
	RenderGame();
    }
    
    DrawButton(255, 300, 90, 30, "PLAY", 0);
    return selectedBallS1, selectedBallS2;
}

void DrawBalls()
{
    Color BallColor = RED;
    DrawCircle(100, 300, 50, BallColor);
}

int main(void)
{
    // TODO(Patryk): Make the arena window independent?
    int screenWidth = 600;
    int screenHeight = 600;
    bool start = false;

    SetTargetFPS(60);
    
    InitWindow(screenWidth, screenHeight, "Arena Sim");

    while (!WindowShouldClose())
    {
	
        BeginDrawing();
            ClearBackground(RAYWHITE);

	    DrawBalls();
	    DrawMenu();

	    if (start == true)
	    {
		DrawText("IT WORKS!", 0, 0, 50, GREEN);
	    }
	    
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
