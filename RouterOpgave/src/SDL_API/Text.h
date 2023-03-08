#pragma once
#include <string>
#include "SDL.h"
#include "../core/Vector.h"
#include "SDL_ttf.h"
#include "Renderer.h"

class SingleLetterText
{
public:
	char Letter;
	SDL_Color Color;
	SDL_Rect Rect{};
};

class Text
{
public:
	static void Init();
	std::string Text;
	SDL_Color color;

	void DrawText(std::string text, Rect rect, Color color);

private:
};