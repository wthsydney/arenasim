#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>

#define internal static
#define local_persist static
#define global_variable static

#define BALL_BASE_SIZE 20.0f
#define DEF_BALL_SPEED 5.0f
#define MAX_BALLS 2

typedef struct Warrior {
    Color COLOR;
    int health;
    int damage;
    float radius;
    Vector2 speed;
    Vector2 position;
    bool active;
} Warrior;

// TODO(Patryk): Those are global for now
global_variable int selectedBallS1 = 0;
global_variable int selectedBallS2 = 0;
global_variable bool gameRunning = false;
global_variable bool gameOver = false;

global_variable Warrior warriors[MAX_BALLS] = { 0 };

global_variable bool victory = false;
global_variable bool lose = false;
// global_variable bool awake = false;

void DrawBalls()
{
    int posx, posy;
    int velx = 0;
    int vely = 0;
    
    // Initialize warriors
    for (int i = 0; i < MAX_BALLS; i++)
    {
        warriors[i].radius = 40.0f;
        posx = GetRandomValue(0 + warriors[i].radius, GetScreenWidth() - warriors[i].radius);
        posy = GetRandomValue(0 + warriors[i].radius, GetScreenHeight()/2);

        warriors[i].position = (Vector2){ posx, posy };

        while ((velx == 0) || (vely == 0))
        {
            velx = GetRandomValue(-DEF_BALL_SPEED, DEF_BALL_SPEED);
            vely = GetRandomValue(-DEF_BALL_SPEED, DEF_BALL_SPEED);
        }

        warriors[i].speed = (Vector2){ velx, vely };
        warriors[i].health = 200;
        warriors[i].active = true;

	printf("%d\n", warriors[i].active);
    }
}

internal void
RenderGame()
{
    DrawBalls();
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
    // DrawRectangleLines(posX, posY, width, height, BLACK);
    DrawText(text, posX, posY, 20, BLACK);
}

// TODO: Figure out how to NOT return multiple variables
internal void
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

        // Draw the button, telling it if it should be selected (isSelected)
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
            selectedBallS2 = i;
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
	gameRunning = true;
	RenderGame();
    }
    
    DrawButton(255, 300, 90, 30, "PLAY", 0);
}

int main(void)
{
    // TODO(Patryk): Make the arena window independent?
    int screenWidth = 600;
    int screenHeight = 600;

    int arenaWidth;
    int arenaHeight;

    // I think I will cap the game at 60 fps
    SetTargetFPS(60);
    
    InitWindow(screenWidth, screenHeight, "Arena Sim");

    // This will make sure the game runs properly regardless of framerate
    // but I don't know if I will use it
    // float deltaTime = GetFrameTime();
    while (!WindowShouldClose())
    {
        BeginDrawing();
	ClearBackground(RAYWHITE);
	if (gameRunning)
	{
	    RenderGame();
	}
	else
	{
	    DrawMenu();
	}
	    
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
