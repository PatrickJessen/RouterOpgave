#pragma once
#include <string>
#include "SDL.h"

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
	std::string Text;
	SDL_Color Color;
};