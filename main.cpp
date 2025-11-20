/*******************************************************************************************
 *
 *   raylib [core] example - input keys
 *
 *   Example complexity rating: [★☆☆☆] 1/4
 *
 *   Example originally created with raylib 1.0, last time updated with raylib 1.0
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
 *   BSD-like license that allows static linking with closed source software
 *
 *   Copyright (c) 2014-2025 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "raylib.h"
#include "src/player.cpp"
#include <iostream>

#define SCREENWIDTH 800
#define SCREENHEIGHT 450

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = SCREENWIDTH;
    const int screenHeight = SCREENHEIGHT;
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - input keys");
    
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    Player *player = new Player(0.97f);
    //--------------------------------------------------------------------------------------
    Object *objects[1] = {player};
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        for (int i = 0; i < (sizeof(objects) / sizeof(*objects)); i++)
        {
            Object *currentObject = objects[i];
            currentObject->onStep();
        }
        // Update
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
        

        for (int i = 0; i < (sizeof(objects) / sizeof(*objects)); i++)
        {
            Object *currentObject = objects[i];
            currentObject->render();
        }


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}