/*******************************************************************************************
 *
 *   An spacegame game engine made using raylib
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
#include "src/Player.hpp"
#include "src/core/ObjectManager.hpp"
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
	Player* player = new Player(0.97f);
	//--------------------------------------------------------------------------------------
	ObjectsManager* objectsManager = ObjectsManager::getInstance();
	objectsManager->addObject(player);
	// Main game loopi
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		objectsManager->handleObjectsInstances();
		auto objects = objectsManager->getActiveObjects();
		for (auto object : *objects)
		{
			object->onStep();
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

		for (auto object : *objects)
		{
			object->render();
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