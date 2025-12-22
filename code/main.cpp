#include "raylib.h"
#include <math.h>

#define internal static
#define local_persist static
#define global_variable static

#define BALL_BASE_SIZE 20.0f
#define DEF_BALL_SPEED 5.0f
#define MAX_BALLS 2

typedef struct Warrior {
    Vector2 position;
    Vector2 speed;
    float radius;
    int health;
    bool active;
    Color COLOR;
} Warrior;


// NOTE: Because this program isn't big I will heavily rely on global
// variables, though as much as I can I should put them in structures.
// TODO?: Put them in structures

// TODO: Make fights window independent
global_variable int screenWidth = 600;
global_variable int screenHeight = 600;

// global_variable int arenaWidth = 600;
// global_variable int arenaHeight = 600;

global_variable int framesCounter = 0;
global_variable bool gameOver = false;
global_variable bool pause = false;

global_variable Warrior balls[MAX_BALLS] = { 0 };

global_variable bool victory = false;
global_variable bool lose = false;
global_variable bool awake = false;

// The most important functions we will use
internal void InitGame(void);         
internal void UpdateGame(void);       
internal void DrawGame(void);         
internal void UnloadGame(void);       
internal void UpdateDrawFrame(void);  

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Arena Sim");
    return 0;
}
