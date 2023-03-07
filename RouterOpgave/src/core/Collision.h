#pragma once
#include "Vector.h"
#include "SDL.h"

class Collision 
{
public:
	static bool InRect(const Rect& rect, int x, int y)
	{
		return ((x >= rect.X && x <= rect.X + rect.W) && (y >= rect.Y && y <= rect.Y + rect.H));
	}

	static bool InRect(const SDL_Rect& rect, int x, int y)
	{
		return ((x >= rect.x && x <= rect.x + rect.w) && (y >= rect.y && y <= rect.y + rect.h));
	}
};
