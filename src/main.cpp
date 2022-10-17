#include "engine.h"
#include "sprite.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Forward function declarations
void Update(float dt);
void RenderFrame(float dt);

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 576

Sprite floorTile;

//=============================================================================
int main(int argc, char* argv[])
{
	if (!InitSDL())
	{
		return 1;
	}

	if (!CreateWindow("The Puzzle Game", WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		return 1;
	}

	floorTile = LoadSprite("assets/floorTile01.png");

	// Push functions to the game loop
	StartLoop(Update, RenderFrame);

	FreeSprite(floorTile);
	CleanUp();
	return 0;
}

//=============================================================================

void Update(float dt)
{
	// Change subsystem of project from Windows to Console
	// in order to see the stderr output
	if (IsKeyDown(SDL_SCANCODE_ESCAPE))
		ExitGame();
}

void RenderFrame(float interpolation)
{
	// Clear screen
	SDL_SetRenderDrawColor(gRenderer, 65, 105, 225, 255);
	SDL_RenderClear(gRenderer);

	// Render 8x8 floor piece
	for (int y = 0; y < 8; ++y)
	{
		for (int x = 0; x < 8; ++x)
		{
			SDL_Rect tileRect = {
				x * floorTile.sourceRect.w,
				y * floorTile.sourceRect.h,
				floorTile.sourceRect.w,
				floorTile.sourceRect.h
			};
			SDL_RenderCopy(gRenderer, floorTile.texture, NULL, &tileRect);
		}
	}
}
