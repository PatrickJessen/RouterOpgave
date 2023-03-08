#pragma once
#include <thread>
#include "Text.h"
#include "Renderer.h"
#include "SDL_ttf.h"

class Textbox
{
public:
	Textbox(const std::string& fontType, SDL_Rect rect, uint32_t textSize);
	~Textbox();

public:
	void Write();
	const Text& GetText() { return text; }
	TTF_Font* GetFont() { return font; }
	SDL_Rect GetRect() { return rect; }

private:
	void OnClick();
private:
	Text text = {};
	SDL_Rect rect = {};
	uint32_t textSize = 0;
	TTF_Font* font;
	bool inFocus = false;
	std::thread onclickThread;
};